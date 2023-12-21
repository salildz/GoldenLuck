#pragma once

#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

using namespace System;
using namespace System::Collections::Generic;

public ref class Deck {
public:
    Deck();
    void shuffleDeck();
    void resetDeck();
    List<Card^>^ cards;

private:
    Random^ random;
};
