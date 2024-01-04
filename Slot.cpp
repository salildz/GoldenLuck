#include "Slot.h"



using namespace System;
using namespace System::Collections::Generic;

namespace GoldenLuck {

	void Slot::playSlot() {													//this function is where the game is played out
		int Roll1 = 0, Roll2 = 0, Roll3 = 0, animationRoll = 0;
		SlotAnimation(animationRoll, Slot1);									//there are 3 rows so we call SlotRoll and SlotAnimation 3 times
		SlotRoll(Roll1, Slot1);
		System::Threading::Thread::Sleep(460);								//this is put here so the slot would have some animation vibes
		SlotAnimation(animationRoll, Slot2);
		SlotRoll(Roll2, Slot2);
		System::Threading::Thread::Sleep(460);
		SlotAnimation(animationRoll, Slot3);
		SlotRoll(Roll3, Slot3);
		System::Threading::Thread::Sleep(460);
		if (checkRoll(Roll1, Roll2, Roll3)) {
			labelBalance->Text = "Credit: " + User::credit.ToString();
		}
		else {
			//lose
			announcer->Text = "YOU LOST";
		}
	}

	bool Slot::checkRoll(int Roll1, int Roll2, int Roll3) {					//to check if user won triple, double or nothing
		if (Roll1 == Roll2 && Roll2 == Roll3) {
			announcer->Text = "YOU WON TRIPLE!";

			User::credit += Convert::ToInt32(comboBox->SelectedItem) * 3;

			return true;
			//wins triple
		}
		else if (Roll1 == Roll2 || Roll1 == Roll3 || Roll2 == Roll3) {
			announcer->Text = "YOU WON DOUBLE!";

			User::credit += Convert::ToInt32(comboBox->SelectedItem) * 2;

			return true;
			//wins double
		}
		return false;
		//house always wins
	}

	void Slot::SlotRoll(int& Roll, PictureBox^ Slot) {						//randomized rolls happen and images get loaded on to the pictureboxes
		Roll = rand() % 5 + 1;
		loadImages(Roll, Slot);
	}

	void Slot::SlotAnimation(int& Roll, PictureBox^ Slot) {					//this is where the so called "animation" happens
		for (int i = 0, a = 60; i < 10; i++, a += 40)						//roll starts to slow down the morer it turns
		{
			SlotRoll(Roll, Slot);
			System::Threading::Thread::Sleep(a);
		}
	} 
	bool Slot::canBet() {
		if (Convert::ToInt32(comboBox->SelectedItem) <= User::credit) {
			return true;
		}
		else return false;
	}
	System::Void Slot::Slot_Load(System::Object^ sender, System::EventArgs^ e) {								//when the game loads for the first time this function is called

		btnRoll->Visible = true;
		Slot1->Visible = false;
		Slot2->Visible = false;
		Slot3->Visible = false;
		comboBox->Visible = true;
		labelBalance->Visible = true;
		labelBalance->Text = "Credit: " + User::credit.ToString();
		labelBalance->Show();

	}
	System::Void Slot::btnRoll_Click(System::Object^ sender, System::EventArgs^ e) {							//when the roll button is clicked roll button gets disabled and the rolling starts
		if (canBet()) {
			User::credit -= Convert::ToInt32(comboBox->SelectedItem);
			labelBalance->Text = "Credit: " + User::credit.ToString();
			btnRoll->Enabled = false;
			btnRoll->Visible = false;
			announcer->Visible = false;
			playSlot();
			announcer->Visible = true;
			btnRoll->Visible = true;
			btnRoll->Enabled = true;
		}
	}
	bool Slot::canBet() {
		if (Convert::ToInt32(comboBox->SelectedItem) <= User::credit) {
			return true;
		}
		else return false;
	}
	System::Void Slot::Slot_Load(System::Object^ sender, System::EventArgs^ e) {								//when the game loads for the first time this function is called

		btnRoll->Visible = true;
		Slot1->Visible = false;
		Slot2->Visible = false;
		Slot3->Visible = false;
		comboBox->Visible = true;
		labelBalance->Visible = true;
		labelBalance->Text = "Credit: " + User::credit.ToString();
		

	}
	System::Void Slot::btnRoll_Click(System::Object^ sender, System::EventArgs^ e) {							//when the roll button is clicked roll button gets disabled and the rolling starts
		if (canBet()) {
			User::credit -= Convert::ToInt32(comboBox->SelectedItem);
			labelBalance->Text = "Credit: " + User::credit.ToString();
			btnRoll->Enabled = false;
			btnRoll->Visible = false;
			announcer->Visible = false;
			playSlot();
			announcer->Visible = true;
			btnRoll->Visible = true;
			btnRoll->Enabled = true;
		}
	}

};