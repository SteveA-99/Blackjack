
#include "Blackjack.h"
#include <iostream>

Blackjack::Blackjack()
{
	srand(time(NULL));

}
Card Blackjack::dealCard()
{
	
	Card e = deck[0];
	deck.erase(deck.begin());
	return e;
	
}

void Blackjack::playGame()
{
	int choice;
	Player user;
	Player dealer;
	if (deck.size() <= 13)
	{
		shuffle();
	}
	dealer.hit(dealCard());
	std::cout << "dealer drew 1st card" << std::endl;
	dealer.hit(dealCard());

	std::cout << "The dealer drew " << std::endl;
	dealer.showHand(1);
	user.hit(dealCard());
	do
	{

		std::cout << "Player's hand " << std::endl;
		user.showHand(0);


		std::cout << "What do you want to do?" << std::endl;
		std::cout << "1. Hit" << std::endl;
		std::cout << "2. Stay" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			user.hit(dealCard());
		}
		if (user.numAce > 0 && user.value > 21)
		{
			user.value -= 10;
			user.numAce--;
		}
		

	} while (user.value <= 21 && choice == 1);

	if (user.value > 21)
	{
		user.showHand(0);

		std::cout << "You busted!" << std::endl;
	}
	else
	{
		std::cout << "Dealer's hand " << std::endl;
		dealer.showHand(0);
		while (dealer.value < 17)
		{
			dealer.hit(dealCard());
			std::cout << "Dealer's hand " << std::endl;
			dealer.showHand(0);
			if (dealer.numAce > 0 && dealer.value > 21)
			{
				dealer.value -= 10;
				dealer.numAce--;


			}

		}
		if (dealer.value > 21)
		{
			std::cout << "dealer bust you win!";
		}
		else if (dealer.value > user.value)
		{
			std::cout << "dealer wins you lose!";
		}
		else
		{
			std::cout << "You win!";
		}

	}
}

void Blackjack::shuffle()
{
	char suits[4] = { 'C', 'H', 'S', 'D' };
	
	for (int i = 0; i < 52; i++)
	{
		Card card = { (i % 13) + 1, suits[i / 13] };
		deck.push_back(card);
	}
	for (int i = 0; i < 100; i++)
	{
		std::swap(deck[rand() % 52], deck[rand() % 52]);
	}

	
}

void Player::hit(Card oCard)
{
	hand.push_back(oCard);
	if (oCard.v >= 10)
	{
		value += 10;
	}
	else if (oCard.v == 1)
	{
		numAce++;
		value += 11;
	}
	else
	{
		value += oCard.v;
	}

}

void Player::showHand(int offset)
{
	std::string cs[4] = { "A","J","Q","K" };
	std::string v;
	for (std::vector<Card>::iterator it = hand.begin()+offset; it != hand.end(); ++it)
	{
		if (it->v > 10)
		{
			v = cs[it->v - 10];
		}
		else if (it->v == 1)
		{
			v = cs[0];
		}
		else
		{
			v = std::to_string (it->v);
		}
		std::cout << ' ' << v << ':' << it->c << '\n';
	}
}

Player::Player()
{
	value = 0;
	numAce = 0;
}



