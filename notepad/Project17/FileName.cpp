//Made by Zain babar and M.Abubakar(21F-9341 & 21F-9278)
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
const int ALPHABET_SIZE = 26;
// TrieNode structure
struct TrieNode {
	bool isWord;
	TrieNode* children[ALPHABET_SIZE];

	TrieNode() : isWord(false) {
		for (int i = 0; i < ALPHABET_SIZE; ++i) {
			children[i] = nullptr;
		}
	}
};

// Trie class
class Trie {
private:
	TrieNode* root;

public:
	Trie() : root(new TrieNode()) {}

	// Insert a word into the Trie
	void insertWord(const string& word) {
		TrieNode* node = root;
		for (char c : word) {
			int index = c - 'a';
			if (!node->children[index]) {
				node->children[index] = new TrieNode();
			}
			node = node->children[index];
		}
		node->isWord = true;
	}

	// Search for a prefix in the Trie
	TrieNode* searchPrefix(const string& prefix) {
		TrieNode* node = root;
		for (char c : prefix) {
			int index = c - 'a';
			if (!node->children[index]) {
				return nullptr;
			}
			node = node->children[index];
		}
		return node;
	}
};

// Function to generate word suggestions using Trie
void generateWordSuggestions(Trie& trie, const string& prefix) {
	TrieNode* prefixNode = trie.searchPrefix(prefix);

	if (prefixNode == nullptr) {
		cout << "No suggestions found." << endl;
		return;
	}

	// Check if the prefix itself is a word
	if (prefixNode->isWord) {
		cout << prefix << endl;
	}

	// Recursively find and print suggestions
	for (int i = 0; i < ALPHABET_SIZE; ++i) {
		if (prefixNode->children[i]) {
			string word = prefix + char('a' + i);
			generateWordSuggestions(trie, word);
		}
	}
}

class node
{
public:
	char data;
	node* left;
	node* right;
	node* top;
	node* bottom;
	node(char val)
	{
		data = val;
		left = NULL;
		right = NULL;
		top = NULL;
		bottom = NULL;
	}
};
class stack
{
public:
	char data;
	stack* nextt;
	stack(char ch)
	{
		data = ch;
		nextt = NULL;
	}
};
void insertinstack(stack*& headd, char ch)
{
	stack* n = new stack(ch);
	if (headd == NULL)
	{
		headd = n;
		return;
	}
	n->nextt = headd;
	headd = n;
}

int topstack(stack*& headd)
{
	char c;
	stack* temp = headd;
	headd = headd->nextt;
	c = temp->data;
	delete temp;
	return c;
}
void emptystack(stack*& headd)
{
	while (headd != NULL)
	{
		topstack(headd);
	}
}
//////////////////////////////////////////////
class notepad
{
public:
	node* head;
	string str;
	int c;
	notepad()
	{
		str = "";
		head = NULL;
		c = 0;
	}

	void insertathead(char val)
	{

		node* n = new node(val);
		if (head == NULL)
		{
			head = n;
			return;
		}
		head->left = n;
		n->right = head;
		head = n;
	}

	void insertatend(char val)
	{
		node* n = new node(val);
		if (head == NULL)
		{
			head = n;
			return;
		}
		node* temp = head;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		temp->right = n;
		n->left = temp;
	}

	void insertatmiddle(int key, char val)
	{
		node* n = new node(val);
		node* temp = head;
		int k = 0;
		while (temp->right != NULL && k != key - 1)
		{
			temp = temp->right;
			k++;
		}
		if (k != key - 1)
		{
			cout << "Key not found" << endl;
			return;
		}
		node* temp1 = temp->right;
		n->left = temp;
		temp->right = n;
		n->right = temp1;
		if (temp1 != NULL)
		{
			temp1->left = n;
		}
	}

	void searchwords(string str2)
	{
		string str1;
		node* temp = head;
		while (temp != NULL)
		{
			str1 = str1 + temp->data;
			temp = temp->right;
		}

		int k = 0, l = 0;
		for (int i = 0; i < str1.length(); i++)
		{
			if (str2[k] == str1[i])
			{
				l = i;
				string str3;
				for (int j = 0; j < str2.length(); j++)
				{
					str3 = str3 + str1[l];
					l++;
				}

				if (str3 == str2)
				{
					cout << "FOUND: " << str3 << endl;
					return;
				}
			}
		}
		cout << "Not found" << endl;
	}


	void display()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->right;
		}

	}

	void copy(int start, int end)
	{
		node* temp = head;
		int s = 0, e = 0;

		while (temp != NULL && s != start)
		{
			temp = temp->right;
			s++;
		}
		while (temp != NULL && e != end)
		{
			str = str + temp->data;
			temp = temp->right;
			e++;
		}
		cout << "string: " << str << endl;
		c++;
	}

	void paste(int start, stack*& headd)
	{
		if (c == 0)
		{
			cout << "Nothing is copied. Please copy text first." << endl;
			return;
		}
		node* temp = head;
		int s = 0;

		while (temp != NULL && s != start)
		{
			temp = temp->right;
			s++;
		}
		for (int i = 0; i < str.length(); i++)
		{
			insertatmiddle(start, str[i]);
			start++;
		}
		c = 0; 
	}


	void addToFile()
	{
		ofstream file;
		file.open("nigga.txt");
		if (file.is_open())
		{
			node* temp = head;
			while (temp != NULL)
			{
				file << temp->data;
				temp = temp->right;
			}
			file.close();
		}
	}
	int deleteathead()
	{
		if (head == NULL)
		{
			return -1;
		}

		node* temp = head;
		char ch = temp->data;
		head = head->right;
		if (head != NULL)
		{
			head->left = NULL;
		}
		delete temp;
		return ch;
	}

	int deleteinmiddle(int key)
	{
		if (head == NULL)
		{
			return -1;
		}

		if (key == 0)
		{
			node* temp = head;
			int value = head->data;
			head = head->right;
			if (head != NULL)
			{
				head->left = NULL;
			}
			delete temp;
			return value;
		}


		node* temp = head;
		int n = 0;
		while (temp != NULL && n < key)
		{
			temp = temp->right;
			n++;
		}

		if (temp == NULL)
		{

			return -1;
		}
		int value = temp->data;
		if (temp->left != NULL)
		{
			temp->left->right = temp->right;
		}
		if (temp->right != NULL)
		{
			temp->right->left = temp->left;
		}
		delete temp;
		return value;
	}
	void replaceword(string wordtoreplace, string originalword)
	{
		node* temp = head;
		int pos = 0;
		string str1;
		string str3;

		while (temp != NULL)
		{
			str1 += temp->data;
			temp = temp->right;
		}

		int k = 0, l = 0;

		for (int i = 0; i < str1.length(); i++)
		{
			if (originalword[k] == str1[i])
			{
				l = i;
				pos = i;
				for (int j = 0; j < originalword.length(); j++)
				{
					str3 += str1[l];
					l++;
				}
				//////////////////
				if (originalword == str3)
				{
					temp = head;
					int n = 0;  // Changed n to start from 0 instead of 1
					int s = pos;

					while (n < pos)  // Changed condition from != to <
					{
						temp = temp->right;
						n++;
					}
					int strLength = originalword.length();
					for (int i = 0; i < strLength; i++)
					{
						deleteinmiddle(pos);
					}

					int replaceLength = wordtoreplace.length();

					for (int i = 0; i < replaceLength; i++)
					{
						insertatmiddle(s, wordtoreplace[i]);
						s++;
					}
					return;
				}

			}
		}
		cout << "Word not found " << endl;
	}
	void displayinstringform()
	{
		string str;
		node* temp = head;
		while (temp != NULL)
		{
			str = str + temp->data;
			temp = temp->right;
		}
		cout << str;
	}
	void deletestring(string str2)
	{
		string str1;
		node* temp = head;
		int point = 0;

		while (temp != NULL)
		{
			str1 = str1 + temp->data;
			temp = temp->right;
		}

		int k = 0, l = 0;
		for (int i = 0; i < str1.length(); i++)
		{
			if (str2[k] == str1[i])
			{
				l = i;
				point = i;
				string str3;
				for (int j = 0; j < str2.length(); j++)
				{
					str3 = str3 + str1[l];
					l++;
				}

				if (str3 == str2)
				{
					while (point < i + str2.length())
					{
						deleteinmiddle(point);
						i--;
					}
					return;
				}
			}
		}
		cout << "not found";
	}

	void undo(stack*& headd)
	{
		node* temp = head;
		while (temp != NULL)
		{
			insertinstack(headd, temp->data);
			temp = temp->right;
		}
		topstack(headd);
		while (head != NULL)
		{
			deleteathead();
		}
		while (headd != NULL)
		{
			insertathead(topstack(headd));
		}
	}
	void totalwords()
	{
		ifstream file;
		int count = 0;
		file.open("nigga.txt");
		string str;
		while (file >> str)
		{
			count++;
		}
		cout << "total words : " << count << endl;
	}
	void mainfunc()
	{
		cout << "_______________________________________" << endl;
		cout << "| + .insert at head                    |" << endl;
		cout << "| - .insert at middle                  |" << endl;
		cout << "| $ .search words                      |" << endl;
		cout << "| ~ .copy                              |" << endl;
		cout << "| & .paste                             |" << endl;
		cout << "| ! or backspace .undo                 |" << endl;
		cout << "| ^ .total words                       |" << endl;
		cout << "| tab .display in linked list form     |" << endl;
		cout << "| @ .display in string form            |" << endl;
		cout << "| | .replace word                      |" << endl;
		cout << "| ? .deletestring                      |" << endl;
		cout << "| > . addtofile                        |" << endl;
		cout << "| esc .to stop writing                 |" << endl;
		cout << "________________________________________" << endl;
	}
};
int main()
{
	notepad np;
	stack* headd = NULL;
	char ch, c;
	int choice, start, end;
	string str,prefix,prefixstr;
	int pos;
	// Read words from a file and insert into the Trie
	Trie trie;
	ifstream file("words.txt");
	if (file.is_open()) {
		string word;
		while (getline(file, word)) {
			trie.insertWord(word);
		}
		file.close();
	}

	np.mainfunc();
	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 27)
			{
				break;
			}
			else if (ch == 43)
			{
				cout << endl;
				cout << "Enter chararcter to add at head : ";
				cin >> c;
				np.insertathead(c);
				system("cls");
				np.mainfunc();
				np.displayinstringform();
			}
			else if (ch == 45)
			{
				cout << endl;
				cout << "Enter character that you want to enter : ";
				cin >> c;
				cout << "Enter position at which you want to enter : ";
				cin >> pos;
				np.insertatmiddle(pos, c);
				system("cls");
				np.mainfunc();
				np.displayinstringform();
			}
			else if (ch == 62)
			{
				np.addToFile();
				system("cls");
				np.displayinstringform();
			}
			else if (ch == 36)
			{
				cout << endl;
				cout << "Enter word you want to search : ";
				cin >> str;
				cout << "searching " << str << endl;
				np.searchwords(str);
				system("pause");
				system("cls");
				np.mainfunc();
				np.displayinstringform();
			}
			else if (ch == 126)
			{
				cout << "Enter starting and ending positions to copy : ";
				cin >> start >> end;
				np.copy(start, end);
				system("cls");
				np.mainfunc();
				np.displayinstringform();
			}
			else if (ch == 38)
			{
				cout << "Enter position where you want to paste : ";
				cin >> pos;
				np.paste(pos, headd);
				system("cls");
				np.mainfunc();
				np.displayinstringform();
			}
			else if (ch == 33 || ch == 8)
			{
				np.undo(headd);
				system("cls");
				np.mainfunc();
				np.displayinstringform();
			}
			else if (ch == 94)
			{
				cout << endl;
				np.totalwords();
				system("pause");
				system("cls");
				np.mainfunc();
				np.displayinstringform();
			}
			else if (ch == 9)
			{
				cout << endl;
				np.display();
				system("pause");
				system("cls");
				np.mainfunc();
				np.displayinstringform();
			}
			else if (ch == 64)
			{
				cout << endl;
				np.displayinstringform();
				system("pause");
				system("cls");
				np.mainfunc();
				np.displayinstringform();
			}
			else if (ch == 124)
			{
				cout << endl;
				string ow, wtr;
				cout << "Enter original word : ";
				cin >> ow;
				cout << "Enter word to replace : ";
				cin >> wtr;
				np.replaceword(wtr, ow);
				system("cls");
				np.mainfunc();
				np.displayinstringform();
			}
			else if (ch == 63)
			{
				cout << endl;
				cout << "Enter word you want to delete : ";
				cin >> str;
				np.deletestring(str);
				system("cls");
				np.mainfunc();
				np.displayinstringform();
			}
			else if (ch == 10)
			{
				cout << endl;
			}
			else
			{
				np.insertatend(ch);
				system("cls");
				np.mainfunc();
				np.displayinstringform();
				cout << endl;
				if (ch == ' ')
				{
					prefix = "";
				}
				else
				{
					prefix = prefix + ch;
					
				}
				if(ch!=' ')
				generateWordSuggestions(trie, prefix);
			}
		}
	}
	np.addToFile();
	return 0;
}
