#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <stdexcept>
#pragma once

class Card {
public:
	Card(); // Constructor
	Card(char newSuit, int newRank); // Constructor with parameters
	char getSuit();
	void setSuit(char newSuit);
	int getRank();
	void setRank(int newRank);


private:
	char suit;
	int rank;
};

#endif // CARD_H
