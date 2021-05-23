#pragma once
#include <string>
#include <stdlib.h>   
#include <time.h> 
#include <vector>



struct Card
{
	int v;
	char c;

};


class Player
{
public:
	
	std::vector<Card> hand;
	int value;
	int numAce;
	void hit(Card); 
	void showHand(int);
	Player();
	

};

class Blackjack
{

private:
	
	std::vector<Card> deck;
	int userValue;
	int dealerValue;

public:
	Blackjack();
	Card dealCard();
	void playGame();
	void shuffle();	

};



