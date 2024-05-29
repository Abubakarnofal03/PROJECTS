const express = require('express');
const WebSocket = require('ws');

const app = express();
const port = 3000;

// Serve the client interface HTML
app.get('/', (req, res) => {
    res.sendFile(__dirname + '/server-interface.html');
});

// Create WebSocket server
const wss = new WebSocket.Server({ noServer: true });

// Map to store clients in each room
const rooms = new Map();

// Counter to track the number of connected clients
let clientCounter = 0;

// Function to broadcast a message to all clients
function broadcastMessage(message, clientName = 'Server') {
    wss.clients.forEach(client => {
        if (client.readyState === WebSocket.OPEN) {
            client.send(JSON.stringify({ message, clientName }));
        }
    });
}

wss.on('connection', ws => {
    console.log('Client connected');
    
    // Increment the client counter and assign the name based on the counter value
    clientCounter++;
    const clientName = clientCounter.toString();

    ws.on('message', message => {
        try {
            const parsedMessage = JSON.parse(message);
            
            if (parsedMessage.message) {
                const { message: clientMessage, recipientId, room, status } = parsedMessage;
                console.log(`Received message from client ${clientName} in room ${room}: ${clientMessage}`);
                
                // Send message to specific recipient if recipientId is provided
                if (recipientId) {
                    wss.clients.forEach(client => {
                        if (client.readyState === WebSocket.OPEN && client.clientName === recipientId) {
                            client.send(JSON.stringify({ message: clientMessage, clientName }));
                        }
                    });
                    return; // Exit the function to avoid further broadcasting
                }
                
                // Broadcast message based on room membership
                if (room) {
                    const clientsInRoom = rooms.get(room);
                    if (clientsInRoom) {
                        for (const client of clientsInRoom) {
                            if (client !== ws && client.readyState === WebSocket.OPEN) {
                                client.send(JSON.stringify({ message: clientMessage, clientName }));
                            }
                        }
                    }
                } else {
                    broadcastMessage(clientMessage, clientName);
                }
                
                // Log message on the server
                console.log(`[${clientName}] ${clientMessage}`);

                // Broadcast status message
                if (status) {
                    broadcastMessage(`Status update: ${status}`, clientName);
                }
            } else if (parsedMessage.file) {
                const { name, type, data } = parsedMessage.file;
                console.log(`Received file from client ${clientName}: ${name}`);

                // Broadcasting file to specific recipient if recipientId is provided
                const recipientId = parsedMessage.recipientId;
                if (recipientId) {
                    wss.clients.forEach(client => {
                        if (client.readyState === WebSocket.OPEN && client.clientName === recipientId) {
                            client.send(JSON.stringify({ file: { name, type, data }, clientName }));
                        }
                    });
                    return; // Exit the function to avoid further broadcasting
                }

                // Broadcasting file to all clients in the same room
                const room = parsedMessage.room;
                if (room) {
                    const clientsInRoom = rooms.get(room);
                    if (clientsInRoom) {
                        for (const client of clientsInRoom) {
                            if (client.readyState === WebSocket.OPEN) {
                                client.send(JSON.stringify({ file: { name, type, data }, clientName }));
                            }
                        }
                    }
                } else {
                    broadcastMessage(`Received file: ${name}`, clientName);
                }
            } else if (parsedMessage.createRoom) {
                const roomName = parsedMessage.createRoom;
                if (!rooms.has(roomName)) {
                    rooms.set(roomName, new Set());
                }
                // Add the client who created the room to the room
                rooms.get(roomName).add(ws);
            } else if (parsedMessage.joinRoom) {
                const roomName = parsedMessage.joinRoom;
                const clientsInRoom = rooms.get(roomName);
                if (clientsInRoom) {
                    clientsInRoom.add(ws);
                }
            } else if (parsedMessage.leaveRoom) {
                const roomName = parsedMessage.leaveRoom;
                const clientsInRoom = rooms.get(roomName);
                if (clientsInRoom) {
                    clientsInRoom.delete(ws);
                }
            }
        } catch (error) {
            console.error('Error parsing incoming message:', error);
        }
    });

    ws.on('close', () => {
        console.log('Client disconnected');
        // Remove the disconnected client from all rooms
        for (const [roomName, clientsInRoom] of rooms.entries()) {
            clientsInRoom.delete(ws);
        }
    });

    // Assign a unique name to the client
    ws.clientName = clientName;
});

const server = app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});

server.on('upgrade', (request, socket, head) => {
    wss.handleUpgrade(request, socket, head, (ws) => {
        wss.emit('connection', ws, request);
    });
});
