#include "CoinFlip.h"
#include <cstdlib>
#include "User.h"
using namespace System;
using namespace System::Collections::Generic;
namespace GoldenLuck {

	System::Void CoinFlip::CoinFlip_Load(System::Object^ sender, System::EventArgs^ e) {
		headsBtn->Enabled = false;
		tailsBtn->Enabled = false;
		label2->Text = "Credit: " + User::credit;
	}
	int CoinFlip::coinFlip() {
		if (rand() % 2 == 0) return 0;
		else return 1;
	}

	bool CoinFlip::coinResult() {
		if (coinChoice == coinFlip()) return true;
		else return false;
	}
	bool CoinFlip::canBet() {
		if (Convert::ToInt32(comboBox->SelectedItem) <= User::credit) {
			return true;
		}
		else return false;
	}void CoinFlip::resetGame() {
		label1->Text = "";
		resultBox->Controls->Clear();
		headsBtn->Enabled = false;
		tailsBtn->Enabled = false;
		buttonBet->Enabled = true;
	}
	void CoinFlip::loadResult() {
		if (pChoice == 1) resultBox->Load("coins\\heads.png");
		else resultBox->Load("coins\\tails.png");
		if (pChoice == coinChoice) {
			label1->Text = "You Win.";
			User::credit += Convert::ToInt32(comboBox->SelectedItem) * 2;
			label2->Text = "Credit: " + User::credit;
		}
		else label1->Text = "You Lose.";

	}
	System::Void CoinFlip::headsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		resetGame();
		coinChoice = 1;
		pChoice = coinFlip();
		loadResult();
		resultBox->Refresh();

	}
	System::Void CoinFlip::tailsBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		resetGame();
		coinChoice = 0;
		pChoice = coinFlip();
		loadResult();
		resultBox->Refresh();

	}
	System::Void CoinFlip::buttonBet_Click(System::Object^ sender, System::EventArgs^ e) {
		resultBox->Image = nullptr;
		if (canBet()) {
			tailsBtn->Enabled = true;
			headsBtn->Enabled = true;
			buttonBet->Enabled = false;
			User::credit -= Convert::ToInt32(comboBox->SelectedItem);
			label2->Text = "Credit: " + User::credit;
		}
		else {
			label1->Text = "You don't have enough credit.";
		}
	}
}