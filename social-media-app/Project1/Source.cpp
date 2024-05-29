#include <iostream>
#include <string>
using namespace std;
class linkedlist
{
public:
    struct node
    {
        int userid;
        string name;
        string profiledetails;
        node* next;
        node(int id, string name, string profiledetails)
        {
            userid = id;
            this->name = name;
            this->profiledetails = profiledetails;
            next = NULL;
        }
    };
    node* head;

    linkedlist()
    {
        head = NULL;
    }

    void insert(int id, string name, string pdetails)
    {
        node* n = new node(id, name, pdetails);
        if (head == NULL)
        {
            head = n;
            return;
        }
        node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    int deletenode(int id)
    {
        if (head == NULL)
        {
            cout << "No id is present" << endl;
            return -1;
        }
        node* temp = head;
        node* prev = nullptr;
        while (temp != NULL && temp->userid != id)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "User with id = " << id << " not found" << endl;
            return -1;
        }
        if (temp == head)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }
        int n = temp->userid;
        delete temp;
        cout << "User with id = " << n << " deleted successfully" << endl;
        return n;
    }
};

const int HASH_TABLE_SIZE = 2000;

class UserHashTable
{
private:
    linkedlist* hash_table[HASH_TABLE_SIZE];

    int hash_function(int user_id)
    {
        return user_id % HASH_TABLE_SIZE;
    }

public:
    UserHashTable()
    {
        for (int i = 0; i < HASH_TABLE_SIZE; ++i)
        {
            hash_table[i] = new linkedlist();
        }
    }

    void add_user(int user_id, string name, string profile_details)
    {
        int hash_index = hash_function(user_id);
        hash_table[hash_index]->insert(user_id, name, profile_details);
    }

    int remove_user(int user_id)
    {
        int hash_index = hash_function(user_id);
        return hash_table[hash_index]->deletenode(user_id);
    }
    // Function to display all users with their IDs and names
    void displayAllUsers()
    {
        for (int i = 0; i < HASH_TABLE_SIZE; ++i)
        {
            linkedlist::node* temp = hash_table[i]->head;
            while (temp != NULL)
            {
                cout << "User ID: " << temp->userid << ", Name: " << temp->name << endl;
                temp = temp->next;
            }
        }
    }
};

class PostCommentsTree
{
private:
    struct TreeNode
    {
        int post_id;
        string post_text;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int id, const string& text)
        {
            post_id = id;
            post_text = text;
            left = nullptr;
            right = nullptr;
        }
    };

    TreeNode* root;

public:
    PostCommentsTree()
    {
        root = nullptr;
    }

    // Function to add a new post
    void addPost(int post_id, const string& post_text)
    {
        root = addPostRecursive(root, post_id, post_text);
    }

    // Recursive helper function to add a new post
    TreeNode* addPostRecursive(TreeNode* node, int post_id, const string& post_text)
    {
        if (node == nullptr)
        {
            return new TreeNode(post_id, post_text);
        }

        if (post_id < node->post_id)
        {
            node->left = addPostRecursive(node->left, post_id, post_text);
        }
        else if (post_id > node->post_id)
        {
            node->right = addPostRecursive(node->right, post_id, post_text);
        }

        return node;
    }

    // Function to add a new comment or reply to a post
    void addComment(int post_id, int comment_id, const string& comment_text)
    {
        TreeNode* post_node = findPost(root, post_id);
        if (post_node != nullptr)
        {
            post_node->post_text += "\nComment " + to_string(comment_id) + ": " + comment_text;
        }
        else
        {
            cout << "Post with ID " << post_id << " not found." << endl;
        }
    }

    // Recursive helper function to find a post in the tree
    TreeNode* findPost(TreeNode* node, int post_id)
    {
        if (node == nullptr || node->post_id == post_id)
        {
            return node;
        }

        if (post_id < node->post_id)
        {
            return findPost(node->left, post_id);
        }
        else
        {
            return findPost(node->right, post_id);
        }
    }

    // Function to display comments and replies under a post
    void displayComments(int post_id)
    {
        TreeNode* post_node = findPost(root, post_id);
        if (post_node != nullptr)
        {
            cout << "Post " << post_node->post_id << ": " << post_node->post_text << endl;
        }
        else
        {
            cout << "Post with ID " << post_id << " not found." << endl;
        }
    }

    // Function to delete all comments and replies under a post
    void deleteComments(int post_id)
    {
        TreeNode* post_node = findPost(root, post_id);
        if (post_node != nullptr)
        {
            post_node->post_text = "This post has been deleted.";
        }
        else
        {
            cout << "Post with ID " << post_id << " not found." << endl;
        }
    }
};
class Post
{
public:
    int post_id;
    int user_id;
    string post_text;
    int likes;
    time_t timestamp;

    Post(int post_id, int user_id, const string& post_text) {
        this->post_id = post_id;
        this->user_id = user_id;
        this->post_text = post_text;
    }
};
class Queue {
private:
    struct QueueNode {
        Post post;
        QueueNode* next;
        QueueNode(Post p) : post(p), next(nullptr) {}
    };

    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(Post post) {
        QueueNode* new_node = new QueueNode(post);
        if (isEmpty()) {
            front = rear = new_node;
        }
        else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    Post peek() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return Post(-1, -1, "");
        }
        else {
            return front->post;
        }
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
class MinHeap
{
private:
    struct HeapNode
    {
        Post post;
        HeapNode* left;
        HeapNode* right;
        HeapNode(Post p) : post(p), left(nullptr), right(nullptr) {}
    };

    HeapNode* root;

    void insertHelper(HeapNode* node, Post post)
    {
        if (node == nullptr)
        {
            root = new HeapNode(post);
            return;
        }

        if (post.timestamp < node->post.timestamp)
        {
            if (node->left == nullptr)
            {
                node->left = new HeapNode(post);
            }
            else
            {
                insertHelper(node->left, post);
            }
        }
        else
        {
            if (node->right == nullptr)
            {
                node->right = new HeapNode(post);
            }
            else
            {
                insertHelper(node->right, post);
            }
        }
    }

    void inorderTraversal(HeapNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        inorderTraversal(node->left);
        cout << "Post ID: " << node->post.post_id << ", User ID: " << node->post.user_id << ", Text: " << node->post.post_text << endl;
        inorderTraversal(node->right);
    }

public:
    MinHeap() : root(nullptr) {}

    void insert(Post post)
    {
        insertHelper(root, post);
    }

    void displayNewsFeed()
    {
        inorderTraversal(root);
    }
};
class NotificationStack {
private:
    struct Notification {
        string message;
        Notification* next;
        Notification(const string& msg) : message(msg), next(nullptr) {}
    };

    Notification* top;

public:
    NotificationStack() : top(nullptr) {}

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(const string& message) {
        Notification* new_notification = new Notification(message);
        if (isEmpty()) {
            top = new_notification;
        }
        else {
            new_notification->next = top;
            top = new_notification;
        }
    }

    void pop() {
        if (!isEmpty()) {
            Notification* temp = top;
            top = top->next;
            delete temp;
        }
    }

    string peek() const {
        if (!isEmpty()) {
            return top->message;
        }
        else {
            return "No notifications.";
        }
    }

    ~NotificationStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

class SocialNetworkGraph
{
private:
    struct FriendshipNode
    {
        int friend_id;
        FriendshipNode* next_friend;
        FriendshipNode(int id)
        {
            friend_id = id;
            next_friend = NULL;
        }
    };
    NotificationStack notifications;
public:
    struct UserGraphNode
    {
        int user_id;
        string name;
        FriendshipNode* friends;
        UserGraphNode* next;
        MinHeap news_feed;
        UserGraphNode(int id, const string& name)
        {
            user_id = id;
            this->name = name;
            friends = nullptr;
            next = nullptr;
        }
    };

    UserGraphNode* head;
    PostCommentsTree post_comments;


    SocialNetworkGraph()
    {
        head = nullptr;
    }

    void add_user(int user_id, const string& name)
    {
        UserGraphNode* new_node = new UserGraphNode(user_id, name);
        new_node->next = head;
        head = new_node;
    }

    UserGraphNode* find_user(int user_id)
    {
        UserGraphNode* temp = head;
        while (temp != NULL)
        {
            if (temp->user_id == user_id)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    string getusername(int user_id)
    {
        UserGraphNode* temp = head;
        while (temp)
        {
            if (temp->user_id == user_id)
            {
                return temp->name;
            }
            temp = temp->next;
        }
        return "";
    }

    void add_friendship(int user_id1, int user_id2)
    {
        UserGraphNode* user1 = find_user(user_id1);
        UserGraphNode* user2 = find_user(user_id2);

        if (user1 && user2)
        {
            FriendshipNode* new_friend1 = new FriendshipNode(user_id2);
            new_friend1->next_friend = user1->friends;
            user1->friends = new_friend1;

            FriendshipNode* new_friend2 = new FriendshipNode(user_id1);
            new_friend2->next_friend = user2->friends;
            user2->friends = new_friend2;
        }
        else
        {
            cout << "One or both users not found. Cannot establish friendship." << endl;
        }
    }

    void displayfriendships()
    {
        string name;
        UserGraphNode* temp = head;
        while (temp != NULL)
        {
            FriendshipNode* friend_temp = temp->friends;
            while (friend_temp != NULL)
            {
                name = getusername(friend_temp->friend_id);
                cout << "User " << temp->user_id << " (" << temp->name << ") is friends with User " << friend_temp->friend_id << " (" << name << ")" << endl;
                friend_temp = friend_temp->next_friend;
            }
            temp = temp->next;
        }
    }

    // Function to add a new post
    void addPost(int user_id, int post_id, const string& post_text)
    {
        UserGraphNode* user = find_user(user_id);
        if (user != NULL)
        {
            post_comments.addPost(post_id, post_text);
        }
        else
        {
            cout << "User with ID " << user_id << " not found." << endl;
        }
    }

    // Function to add a new comment or reply to a post
    void addComment(int user_id, int post_id, int comment_id, const string& comment_text)
    {
        UserGraphNode* user = find_user(user_id);
        if (user != nullptr)
        {
            post_comments.addComment(post_id, comment_id, comment_text);
        }
        else
        {
            cout << "User with ID " << user_id << " not found." << endl;
        }
    }

    // Function to display comments and replies under a post
    void displayComments(int post_id)
    {
        post_comments.displayComments(post_id);
    }

    // Function to delete all comments and replies under a post
    void deleteComments(int post_id)
    {
        post_comments.deleteComments(post_id);
    }
    //display all post related to a user
    void displayUserPosts(int user_id)
    {
        UserGraphNode* user = find_user(user_id);
        if (user != nullptr)
        {
            cout << "Posts by User " << user->user_id << " (" << user->name << "):" << endl;
            post_comments.displayComments(user_id);
        }
        else
        {
            cout << "User with ID " << user_id << " not found." << endl;
        }
    }
    void sendNotification(int user_id, const string& notification) {
        UserGraphNode* user = find_user(user_id);
        if (user != nullptr) {
            notifications.push(notification);
        }
        else {
            cout << "User with ID " << user_id << " not found." << endl;
        }
    }

    string viewNotification(int user_id) {
        UserGraphNode* user = find_user(user_id);
        if (user != nullptr) {
            return notifications.peek();
        }
        else {
            cout << "User with ID " << user_id << " not found." << endl;
            return "No notifications.";
        }
    }

    void clearNotifications(int user_id) {
        UserGraphNode* user = find_user(user_id);
        if (user != nullptr) {
            while (!notifications.isEmpty()) {
                notifications.pop();
            }
        }
        else {
            cout << "User with ID " << user_id << " not found." << endl;
        }
    }
};

int main()
{
    UserHashTable hashtable;
    SocialNetworkGraph friendships;
    string choice;
    int c;
    int id = 0, n;
    int user1, user2;
    string name1, name2;
    string name, details;
    while (true)
    {
        cout << "----------------------------" << endl;
        cout << "| 1. ADD USER              |" << endl;
        cout << "| 2. REMOVE USER           |" << endl;
        cout << "| 3. BUILD FRIENDSHIP      |" << endl;
        cout << "| 4. display friendships   |" << endl;
        cout << "| 5. ADD POST              |" << endl;
        cout << "| 6. ADD COMMENT           |" << endl;
        cout << "| 7. DISPLAY COMMENTS      |" << endl;
        cout << "| 8. DELETE COMMENTS       |" << endl;
        cout << "| 9. DISPLAY ALL USERS     |" << endl;
        cout << "| 10. GENERATE NEWS FEED   |" << endl;
        cout << "| 11. SEND NOTIFICATIONS   |" << endl;
        cout << "| 12. VIEW NOTIFICATION    |" << endl;
        cout << "| 13. clear notifications  |" << endl;
        cout << "----------------------------" << endl;
        cin >> choice;
        c = stoi(choice);//string converting to int type
        switch (c)
        {
        case 1:
        {
            cout << "Enter user name : ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter details (gender, age, married/unmarried) : ";
            getline(cin, details);
            hashtable.add_user(id, name, details);
            cout << "User saved with id # " << id << endl;
            friendships.add_user(id, name);
            id++;
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            cout << "Enter id# of user to remove : ";
            cin >> n;
            int deletedid;
            deletedid = hashtable.remove_user(n);
            if (deletedid != -1)
            {
                cout << "User with " << deletedid << " deleted successfully" << endl;
            }
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            cout << "Enter user 1 id : ";
            cin >> user1;
            cout << "Enter user 2 id : ";
            cin >> user2;
            name1 = friendships.getusername(user1);
            name2 = friendships.getusername(user2);

            friendships.add_user(user1, name1);
            friendships.add_user(user2, name2);
            friendships.add_friendship(user1, user2);
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            friendships.displayfriendships();
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            int post_id, user_id;
            string post_text;
            cout << "Enter user ID: ";
            cin >> user_id;
            cout << "Enter post ID: ";
            cin >> post_id;
            cout << "Enter post text: ";
            cin.ignore();
            getline(cin, post_text);
            friendships.addPost(user_id, post_id, post_text);

            // Update user's news feed with the new post
            Post new_post(post_id, user_id, post_text);
            SocialNetworkGraph::UserGraphNode* user = friendships.find_user(user_id);
            if (user != nullptr)
            {
                user->news_feed.insert(new_post);
            }
            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            int post_id, comment_id, user_id;
            string comment_text;
            cout << "Enter user ID: ";
            cin >> user_id;
            cout << "Enter post ID: ";
            cin >> post_id;
            cout << "Enter comment ID: ";
            cin >> comment_id;
            cout << "Enter comment text: ";
            cin.ignore();
            getline(cin, comment_text);
            friendships.addComment(user_id, post_id, comment_id, comment_text);
            system("pause");
            system("cls");
            break;
        }
        case 7:
        {
            int post_id;
            cout << "Enter post ID: ";
            cin >> post_id;
            friendships.displayComments(post_id);
            system("pause");
            system("cls");
            break;
        }
        case 8:
        {
            int post_id;
            cout << "Enter post ID: ";
            cin >> post_id;
            friendships.deleteComments(post_id);
            system("pause");
            system("cls");
            break;
        }
        case 9:
        {

            hashtable.displayAllUsers();
            system("pause");
            system("cls");
            break;
        }
        case 10:
        {
            int user_id;
            cout << "Enter user ID: ";
            cin >> user_id;

            SocialNetworkGraph::UserGraphNode* user = friendships.find_user(user_id);
            if (user != nullptr)
            {
                cout << "News feed for User " << user->user_id << " (" << user->name << "):" << endl;
                user->news_feed.displayNewsFeed();
            }
            else
            {
                cout << "User with ID " << user_id << " not found." << endl;
            }
            system("pause");
            system("cls");
            break;
        }
        case 11:
        {
            int user_id;
            string notification;
            cout << "Enter user ID to send notification: ";
            cin >> user_id;
            cin.ignore();
            cout << "Enter notification message: ";
            getline(cin, notification);
            friendships.sendNotification(user_id, notification);
            system("pause");
            system("cls");
            break;
        }
        case 12:
        {
            int user_id;
            cout << "Enter user ID to view notification: ";
            cin >> user_id;
            string notification = friendships.viewNotification(user_id);
            cout << "Notification for User " << user_id << ": " << notification << endl;
            system("pause");
            system("cls");
            break;
        }
        case 13:
        {
            int user_id;
            cout << "Enter user ID to clear notifications: ";
            cin >> user_id;
            friendships.clearNotifications(user_id);
            system("pause");
            system("cls");
            break;
        }
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    return 0;
}
