/*
This is blackjack where you will be given one card and will have the options to either hit or stay and you need to get 21 or close to beat the dealer
*/

#include <iostream>
#include "Blackjack.h"

using namespace std;

int menu();
void pauseScreen2();
void pauseScreen();
void clearScreen();


int main()
{
	int input = 0;
	Blackjack b;
	cout << "***Welcome to Blackjack!***" << endl;
	pauseScreen2();
	clearScreen();
	do
	{
		input = menu();

		switch (input)
		{
		case 1:
			b.playGame();
			b.shuffle();
			b.dealCard();
			pauseScreen();
			break;

		case 2:
			cout << "Rules:" << endl;
			cout << "1. Draw one card" << endl;
			cout << "2. ask to draw a card or pass" << endl;
			cout << "3. Try and get close to 21 or try and get 21" << endl;
			cout << "4. A are worth 1 or 11, J, Q, and K are worth 10" << endl;
			pauseScreen();
			break;

		case 3:

			cout << "What do you want to do?" << endl;
			cout << "1. Draw two cards" << endl;
			cout << "2. shuffle" << endl;
			
			
			cin >> input;
			switch (input)
			{

			case 1:
				b.playGame();
				b.shuffle();
				b.dealCard();
				break;
			case 2:
				b.shuffle();
				cout << "You have shuffled the deck!" << endl;
				break;
			case 3:
				b.playGame();
				b.shuffle();
				b.dealCard();
				break;

			}
			
			
			pauseScreen();
			break;
			
		
		}

		clearScreen();
	} while (input != 4);

	return 0;
}


int menu()
{
	int input;
	cout << "***Blackjack***" << endl;
	cout << "1. Start game" << endl;
	cout << "2. How to play the game" << endl;
	cout << "3. Test run" << endl;
	cout << "4. Quit" << endl;
	cout << "Enter Choice: " << endl;
	cin >> input;
	while (input < 1 or input > 4)
	{
		cout << "Enter a valid menu item" << endl;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		cin >> input;
	}
	return input;
}


void pauseScreen()
{
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Enter to continue!" << endl;
	cin.get();
}

void clearScreen()
{

	system("CLS");
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
	}
}
void pauseScreen2()
{
	cout << "Enter to continue!" << endl;
	cin.get();
}








