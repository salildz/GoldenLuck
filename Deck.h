#pragma once
#include "Card.h"
#include <vcclr.h>

using namespace System;
using namespace System::Collections::Generic;

public ref class Deck {
private:
    List<Card^>^ cards; // List to hold cards in the deck

public:
    Deck(); // Constructor to create a deck of cards
    void createDeck(); // Function to create a standard deck of cards
    void shuffleDeck(); // Function to shuffle the deck
    Card^ dealCard(); // Function to deal a card from the deck
};
