#pragma once

#include "Card.h"
#include <vector>

using namespace System;
using namespace System::Collections::Generic;

public ref class Hand {
public:
	Hand();
	void addCardToHand(Card^ newCard);
	int getSum();
	void addSum(int add);
	int getAceCount();
	void addAceCount(int add);
	void resetHand();
	List<Card^>^ getHand();
	int getSumForDealer();



private:
	int sum;
	int aceCount;
	List<Card^>^ cards;
};
