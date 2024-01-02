#include "BlackJack.h"

/*usera 1 kart a��k dealer 1 kart a��k
usera 1 kart a��k dealer 1 kart kapal�
user ne kadar isterse �ekiyor
21den fazlaysa bitiyor
user 21se dealer a��yor
user 21 alt�ysa dealer a��yor


		dealer 16 veya azsa ba�ka bir kart almak zorunda
		dealer 17 veya fazlaysa kalmak zorunda

21 yaparsan 1,5 kat�n� al�yorsun
dealer 21 �zerine ��karsa user 2 kat�n� al�yor
user normal kazan�rsa*/
using namespace System;
using namespace System::Collections::Generic;

namespace GoldenLuck {


	void BlackJack::initializeGame() {
		userHand = gcnew Hand();
		dealerHand = gcnew Hand();
		deck = gcnew Deck();
		deck->shuffleDeck();
		dealCard(userHand);
		dealHiddenCard(dealerHand);
		dealCard(userHand);
		dealCard(dealerHand);
	}
	void BlackJack::resetGame() {
		if (userHand != nullptr && dealerHand != nullptr) {
			userHand = nullptr;
			dealerHand = nullptr;
		}
	}

	void BlackJack::dealHiddenCard(Hand^ hand) {
		Card^ temp1 = deck->cards[deck->cards->Count - 1];
		temp1->makeHidden();
		hand->addCardToHand(temp1);


		//Ace and JQK check
		if (temp1->getRank() == 1) {
			hand->addSum(11);
			hand->addAceCount(1);
		}
		else if (temp1->getRank() == 11 || temp1->getRank() == 12 || temp1->getRank() == 13) {
			hand->addSum(10);
		}
		else {
			hand->addSum(temp1->getRank());
		}

		deck->cards->RemoveAt(deck->cards->Count - 1);
	}



	void BlackJack::dealCard(Hand^ hand) {
		Card^ temp2 = deck->cards[deck->cards->Count - 1];
		hand->addCardToHand(temp2);

		//Ace and JQK check
		if (temp2->getRank() == 1) {
			hand->addSum(11);
			hand->addAceCount(1);
		}
		else if (temp2->getRank() == 11 || temp2->getRank() == 12 || temp2->getRank() == 13) {
			hand->addSum(10);
		}
		else {
			hand->addSum(temp2->getRank());
		}

		deck->cards->RemoveAt(deck->cards->Count - 1);
	}

	int BlackJack::reduceDealerAce() {
		while (dealerHand->getSum() > 21 && dealerHand->getAceCount() > 0) {
			dealerHand->addSum(-10);
			dealerHand->addAceCount(-1);
		}
		return dealerHand->getSum();
	}

	int BlackJack::reduceUserAce() {
		while (userHand->getSum() > 21 && userHand->getAceCount() > 0) {
			userHand->addSum(-10);
			userHand->addAceCount(-1);
		}
		return userHand->getSum();
	}

	bool BlackJack::isBlackJack(Hand^ hand) {
		return (hand->getSum() == 21);
	}


}