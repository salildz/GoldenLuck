#include "BlackJack.h"

/*usera 1 kart açýk dealer 1 kart açýk
usera 1 kart açýk dealer 1 kart kapalý
user ne kadar isterse çekiyor
21den fazlaysa bitiyor
user 21se dealer açýyor
user 21 altýysa dealer açýyor


		dealer 16 veya azsa baþka bir kart almak zorunda
		dealer 17 veya fazlaysa kalmak zorunda

21 yaparsan 1,5 katýný alýyorsun
dealer 21 üzerine çýkarsa user 2 katýný alýyor
user normal kazanýrsa*/
using namespace System;
using namespace System::Collections::Generic;

namespace GoldenLuck {


	void BlackJack::initializeGame() {
		userHand = gcnew Hand();
		dealerHand = gcnew Hand();
		deck = gcnew Deck();
		deck->shuffleDeck();
		bet = 200;
		dealCard(userHand);
		dealHiddenCard(dealerHand);
		dealCard(userHand);
		dealCard(dealerHand);
		/*int j = 1;
		for each (Card ^ card in deck->cards) {
			Console::WriteLine("{0} {1}  {2}", card->getSuit(), card->getRank(), j++);
		}
		Console::WriteLine("Hidden: {0} {1}", dealerHand->getHiddenCard()->getSuit(), dealerHand->getHiddenCard()->getRank());
		Console::Write("Dealer: ");
		for each (Card ^ card in dealerHand->getHand()) {
			Console::WriteLine("{0} {1}", card->getSuit(), card->getRank());
		}
		Console::Write("User: ");
		for each (Card ^ card in userHand->getHand()) {
			Console::WriteLine("{0} {1}", card->getSuit(), card->getRank());
		}*/
	}
	void BlackJack::resetGame() {
		if (userHand != nullptr && dealerHand != nullptr) {
			userHand = nullptr;
			dealerHand = nullptr;
		}
	}

	void BlackJack::dealHiddenCard(Hand^ hand) {
		Card^ temp1 = deck->cards[deck->cards->Count - 1];
		hand->setHiddenCard(temp1);
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