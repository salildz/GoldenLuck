#include "Slot.h"
#include <windows.h>

using namespace System;
using namespace System::Collections::Generic;

namespace GoldenLuck {

	void Slot::playSlot() {
		int Roll1 = 0, Roll2 = 0, Roll3 = 0, animationRoll = 0;
		SlotAnimation(animationRoll,Slot1);
		SlotRoll(Roll1, Slot1);
		SlotAnimation(animationRoll,Slot2);
		SlotRoll(Roll2, Slot2);
		SlotAnimation(animationRoll,Slot3);
		SlotRoll(Roll3, Slot3);
		if (checkRoll(Roll1, Roll2, Roll3)) {
			//win
			;
		}
		else {
			//lose
			announcer->Text = "YOU LOSE";
		}
		
	}

	bool Slot::checkRoll(int Roll1, int Roll2, int Roll3) {
		if (Roll1 == Roll2 && Roll2 == Roll3) {
			announcer->Text = "YOU WON TRIPLE!";
			return true;
			//wins triple
		}
		else if (Roll1 == Roll2 || Roll1 == Roll3 || Roll2 == Roll3) {
			announcer->Text = "YOU WON DOUBLE!";
			return true;
			//wins double
		}
		return false;
	}

	void Slot::SlotRoll(int& Roll,PictureBox^ Slot) {
		Roll = rand() % 5 + 1;
		loadImages(Roll,Slot);
	}

	void Slot::SlotAnimation(int& Roll,PictureBox^ Slot) {
		for (int i = 0; i < 10; i++)
		{
			SlotRoll(Roll,Slot);
			System::Threading::Thread::Sleep(60);
		}
	}

};