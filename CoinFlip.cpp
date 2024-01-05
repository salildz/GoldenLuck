#include "CoinFlip.h"
#include <cstdlib>

using namespace System;
using namespace System::Collections::Generic;
using namespace std;

namespace GoldenLuck {


	int CoinFlip::coinFlip() {
		if (rand() % 2 == 0) return 0;
		else return 1;
	}

	bool CoinFlip::coinResult() {
		if (coinChoice == coinFlip()) return true;
		else return false;
	}
}