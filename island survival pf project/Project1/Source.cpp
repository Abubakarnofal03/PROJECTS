#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void instructions()
{
	cout << "---------------welcome to ESCAPE FROM ISLAND game----------------" << endl;
	cout << "You have one boat and 10 pots at starting " << endl;
	cout << "You have to gain $1000 to get a ticket for boat in 10 days " << endl;
}
int weather()
{
	int w;
	srand(time(0));
	w = 1 + rand() % 6;
	return w;
}
void pots()
{
	int w;
	char ch, p;
	int harbor[30], open[30], h = 0, o = 0, n[30], boats = 1, pots = 10, nofpots, money = 0, m = 0, g = 0;
	for (int i = 0; i < 30; i++)
	{

		cout << endl;
		cout << "Let's start work for day " << i << endl << endl;
		n[i] = weather();
		if (n[i] == 1 || n[i] == 2 || n[i] == 3)
		{
			cout << "weather is clear " << endl;

		}
		else if (n[i] == 5 || n[i] == 6)
		{
			cout << "weather is stormy" << endl;
		}
		cout << "how many pots you want to put on harbor : ";
		cin >> h;
		cout << "How many pots you want to put in open sea : ";
		cin >> o;
		cout << endl;
		if ((h + o) > pots)
		{
			cout << "insufficient pots! Enter again" << endl;
			cin >> h;
			cin >> o;
		}
		cout << endl;

		if (n[i] == 1 || n[i] == 2 || n[i] == 3)
		{
			harbor[i] = h * 2;
			open[i] = o * 8;
			cout << endl;
			cout << "you earned $ " << harbor[i] << " from harbor pots for day " << i << endl;
			money = money + harbor[i];
			cout << endl;
			cout << "you earned $ " << open[i] << " from open sea pots for day " << i << endl;
			money = money + open[i];
			cout << endl;
			cout << "Total Balance = " << money << endl;
		}
		else if (n[i] == 5 || n[i] == 6)
		{

			harbor[i] = h * 4;
			money = money + harbor[i];
			cout << endl;
			cout << "You earned $ " << harbor[i] << " from harbor pots for day " << i << endl;
			cout << endl;
			cout << "You,ve lost " << o << " pots due to stormy weather " << endl;
			pots = pots - o;
			cout << "Remaining pots = " << pots << endl;
			cout << endl;
			cout << "Total balance = " << money << endl;
		}
		else if (n[i] == 4)
		{
			g = n[i - 1];
			if (h == 1 || h == 2 || h == 3)
			{
				cout << "Weather is clear" << endl;
				harbor[i] = h * 2;
				money = money + harbor[i];
				open[i] = o * 8;
				money = money + open[i];
				cout << endl;
				cout << "you earned $" << harbor[i] << "from harbor pots for day " << i << endl;
				cout << "you earned $" << open[i] << " from open sea pots for day " << i << endl;
				cout << endl;
				cout << "total balance = " << money << endl;
			}
			else if (h == 5 || h == 6)
			{

				harbor[i] = h * 4;
				money = money + harbor[i];
				cout << endl;
				cout << "You earned $" << harbor[i] << "from harbor pots for day " << i << endl;
				cout << "you,ve lost " << o << " pots due to stormy weather " << endl;
				cout << endl;
				cout << "total balance = " << money << endl;

			}
			else
			{

				harbor[i] = h * 2;
				money = money + harbor[i];
				open[i] = o * 8;
				money = money + open[i];
				cout << endl;
				cout << "you earned $" << harbor[i] << "from harbor pots for day " << i << endl;
				cout << "you earned $" << open[i] << " from open sea pots for day " << i << endl;
				cout << endl;
				cout << "total balance = " << money << endl;
			}
		}
		cout << endl;
		cout << "Do you want to buy new boat (y/n) : ";
		cin >> ch;
		cout << endl;
		if (ch == 'y')
		{
			if (money < 100)
			{
				cout << "Insufficient balance" << endl;
			}
			else
			{
				boats++;
				cout << "Now you have " << boats << " boats in total" << endl;

				money = money - 100;
				cout << "Remaining Balance = " << money << endl;
			}
		}
		else
		{
			cout << "You still have " << boats << "boats" << endl;
		}
		cout << "Do you want to buy more pots(y/n) : ";
		cin >> p;
		cout << endl;
		if (p == 'y')
		{
			if (money < 5)
			{
				cout << "Insufficient balance" << endl;
			}
			else
			{
				cout << "How many pots you want to buy? : ";
				cin >> nofpots;
				pots = pots + nofpots;
				cout << "You have total " << pots << " pots in total " << endl;
				money = money - (nofpots * 5);
				cout << endl;
				cout << "Remaining balance = " << money << endl;
			}
		}
		else
		{
			cout << "you have total " << pots << " pots" << endl;
		}
		if (money >= 1000)
		{
			cout << "you have succesfully collected $1000 to buy a ticket" << endl;
			break;
		}
	}
}
void credits()
{
	cout << "Developed by M. Abubakar :)" << endl;
}
int main()
{
	int choice;
	do {
		cout << "1. START GAME " << endl;
		cout << "2. CREDITS" << endl;
		cout << "3. INSTRUCTIONS " << endl;
		cout << "4. exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			instructions();
			cout << endl;
			pots();
		}
		case 2:
		{
			credits();
			system("pause");
			system("CLS");
			break;
		}
		case 3:
		{
			instructions();
			system("pause");
			system("CLS");
		}
		case 4:
		{
			exit(0);

		}
		}
	} while (1);
	return 0;
}


