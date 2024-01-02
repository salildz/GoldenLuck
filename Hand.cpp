#include "Hand.h"

Hand::Hand() {
	sum = 0;
	aceCount = 0;
	cards = gcnew List<Card^>();
}

void Hand::addCardToHand(Card^ newCard) {
	cards->Add(newCard);
}


void Hand::resetHand() {
	cards->Clear();
}

List<Card^>^ Hand::getHand() {
	return cards;
}

int Hand::getSum() {
	return sum;
}

void Hand::addSum(int add) {
	sum += add;
}

int Hand::getAceCount() {
	return aceCount;
}

void Hand::addAceCount(int add) {
	aceCount += add;
}

int Hand::getSumForDealer() {
	int temp = 0;
	for (int i = 0; i < cards->Count; i++)
	{
		if (cards[i]->isFaceUp()) {

			if (cards[i]->getRank() == 1) {
				temp += 11;
			}
			else if (cards[i]->getRank() == 11 || cards[i]->getRank() == 12 || cards[i]->getRank() == 13) {
				temp += 10;
			}
			else {
				temp += cards[i]->getRank();
			}
		}
	}
	return temp;
}