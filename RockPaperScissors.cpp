#include "RockPaperScissors.h"
#include <cstdlib>

using namespace System;
using namespace System::Collections::Generic;
using namespace std;

namespace GoldenLuck {							
	static int round = 1, scoreP = 0, scoreD = 0;					

	char Pchoice = ' ', Dchoice = ' ';

	void RockPaperScissors::playRPSround(){				//each round gets played using this function
		round++;
		lblRound->Text = "Round " + round;
		Dchoicegenerator();								
		loadImages();									
		calculatescore();								
		lblP->Text = scoreP.ToString();
		lblD->Text = scoreD.ToString();
		if (round == 6) {
			endGame();
		}
		
	}

	void RockPaperScissors::calculatescore() {			//this function finds out who won the round
		if (Pchoice == Dchoice) {
			 }

		else if ((Pchoice == 'S' && Dchoice == 'P') ||
				 (Pchoice == 'R' && Dchoice == 'S') ||
				 (Pchoice == 'P' && Dchoice == 'R')) {
			scoreP++;
			 }

		else if ((Pchoice == 'P' && Dchoice == 'S') ||
				 (Pchoice == 'R' && Dchoice == 'P') ||
				 (Pchoice == 'S' && Dchoice == 'R'))  {
			scoreD++;
			 }
	}

	void RockPaperScissors::Dchoicegenerator() {		//this generates a choice for the dealer/computer
		int choice = rand() % 3;						
		switch (choice)
		{
		case 0:
			Dchoice = 'R';
			break;
		case 1:
			Dchoice = 'P';
			break;
		case 2:
			Dchoice = 'S';
			break;
		}
	}
}