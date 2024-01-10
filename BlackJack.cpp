#include "BlackJack.h"

using namespace System;
using namespace System::Collections::Generic;

namespace GoldenLuck {


	void BlackJack::initializeGame() { //Creates necessary components such as deck and hands. Deals cards for initialization.
		userHand = gcnew Hand();
		dealerHand = gcnew Hand();
		deck = gcnew Deck();
		deck->shuffleDeck();
		dealCard(userHand);
		dealHiddenCard(dealerHand);
		dealCard(userHand);
		dealCard(dealerHand);
	}
	void BlackJack::resetGame() { //Resets each hands.
		if (userHand != nullptr && dealerHand != nullptr) {
			userHand = nullptr;
			dealerHand = nullptr;
		}
	}

	void BlackJack::dealHiddenCard(Hand^ hand) { //Takes the last card of the deck, then assigns it to the target hand as hidden.
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



	void BlackJack::dealCard(Hand^ hand) { //Takes the last card of the deck, then assigns it to the hand.
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

	int BlackJack::reduceDealerAce() { //It is one of the BlackJack properties. You can use your ace card as 1 or 11 depends on your current hand. This method converts ace's value 11 to 1 for the dealer. 
		while (dealerHand->getSum() > 21 && dealerHand->getAceCount() > 0) {
			dealerHand->addSum(-10);
			dealerHand->addAceCount(-1);
		}
		return dealerHand->getSum();
	}

	int BlackJack::reduceUserAce() { //It is one of the BlackJack properties. You can use your ace card as 1 or 11 depends on your current hand. This method converts ace's value 11 to 1 for the user. 
		while (userHand->getSum() > 21 && userHand->getAceCount() > 0) {
			userHand->addSum(-10);
			userHand->addAceCount(-1);
		}
		return userHand->getSum();
	}

	bool BlackJack::isBlackJack(Hand^ hand) { //Checks if hand is blackjack.
		return (hand->getSum() == 21);
	}

	void BlackJack::printCredit() { //Updates credit label.
		lblBalance->Text = "Credit: " + User::credit.ToString();
	}

	void BlackJack::loadDealerCardImages() { //Prints the dealer's cards.
	
		array<PictureBox^>^ cardPictureBoxes1 = gcnew array<PictureBox^>(dealerHand->getHand()->Count);

		for (int i = 0; i < dealerHand->getHand()->Count; i++)
		{
			cardPictureBoxes1[i] = gcnew PictureBox();
			cardPictureBoxes1[i]->SizeMode = PictureBoxSizeMode::Zoom;
			cardPictureBoxes1[i]->Location = Point(i * 110, 10); 
			cardPictureBoxes1[i]->Size = System::Drawing::Size(110, 154);

			if (dealerHand->getHand()[i]->isFaceUp()) {
				if (i == 0) {
					pnlGame->Controls->RemoveAt(0);
				}
				cardPictureBoxes1[i]->Image = Image::FromFile("cards\\" + dealerHand->getHand()[i]->getRank() + "-" + dealerHand->getHand()[i]->getSuit() + ".png");
			}
			else {
				cardPictureBoxes1[i]->Image = Image::FromFile("cards\\BACK.png");
			}
			pnlGame->Controls->Add(cardPictureBoxes1[i]);
		}

		pnlGame->Controls->Add(lblDealer);
		if (dealerHand->getHand()[0]->isFaceUp()) {
			lblDealer->Text = "Dealer: " + reduceDealerAce();
		}
		else {
			lblDealer->Text = "Dealer: " + dealerHand->getSumForDealer();
		}

	}

	void BlackJack::loadUserCardImages() { //Prints the user's cards.
		array<PictureBox^>^ cardPictureBoxes2 = gcnew array<PictureBox^>(userHand->getHand()->Count);

		
		for (int i = 0; i < userHand->getHand()->Count; i++)
		{
			cardPictureBoxes2[i] = gcnew PictureBox();
			cardPictureBoxes2[i]->SizeMode = PictureBoxSizeMode::Zoom; 
			cardPictureBoxes2[i]->Location = Point(i * 110, 366); 
			cardPictureBoxes2[i]->Size = System::Drawing::Size(110, 154); 
			cardPictureBoxes2[i]->Image = Image::FromFile("cards\\" + userHand->getHand()[i]->getRank() + "-" + userHand->getHand()[i]->getSuit() + ".png");
			pnlGame->Controls->Add(cardPictureBoxes2[i]); 

		}
		pnlGame->Controls->Add(lblUser);
		if (userHand->getSum() > 21) {
			lblUser->Text = "User: " + reduceUserAce();
		}
		else {
			lblUser->Text = "User: " + userHand->getSum();
		}

	}

	void BlackJack::endGame() { //Checks the last status of the game and ends up the game by deciding win/tie/lose.
		if (reduceUserAce() > 21) {
			lblResult->Text = "You Lose!";
			btnHit->Enabled = false;
			btnStay->Enabled = false;
			faceUpDealerHand();
			printCredit();
		}
		else if (reduceDealerAce() > 21) {
			lblResult->Text = "You Win!";
			btnHit->Enabled = false;
			btnStay->Enabled = false;
			faceUpDealerHand();
			User::credit += Convert::ToInt32(comboBox->SelectedItem) * 2;
			printCredit();
		}
		else if (reduceUserAce() == reduceDealerAce()) {
			lblResult->Text = "Tie!";
			btnHit->Enabled = false;
			btnStay->Enabled = false;
			faceUpDealerHand();
			User::credit += Convert::ToInt32(comboBox->SelectedItem);
			printCredit();
		}
		else if (reduceUserAce() > reduceDealerAce()) {
			lblResult->Text = "You Win!";
			btnHit->Enabled = false;
			btnStay->Enabled = false;
			faceUpDealerHand();
			User::credit += Convert::ToInt32(comboBox->SelectedItem) * 2;
			printCredit();
		}
		else if (reduceUserAce() < reduceDealerAce()) {
			lblResult->Text = "You Lose!";
			btnHit->Enabled = false;
			btnStay->Enabled = false;
			faceUpDealerHand();
			printCredit();

		}
		pnlGame->Controls->Add(lblResult);
		btnStart->Enabled = true;
		comboBox->Visible = true;
	}

	void BlackJack::faceUpDealerHand() { //Faces up the dealer's hidden card.
		dealerHand->getHand()[0]->makeVisible();

		loadDealerCardImages();
		loadUserCardImages();
		pnlGame->Refresh();
	}

	bool BlackJack::canBet() { //Checks if user have enough credit.
		if (Convert::ToInt32(comboBox->SelectedItem) <= User::credit) {
			return true;
		}
		else return false;
	}

}