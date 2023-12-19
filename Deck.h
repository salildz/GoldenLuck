#pragma once
#include "Card.h"
#include <vcclr.h>
#include <vector>

public ref class Deck {
private:
    System::Collections::Generic::List<Card^>^ cards; // List to hold cards in the deck

public:
    Deck(); // Constructor to create a deck of cards
    void createDeck(); // Function to create a standard deck of cards
    void shuffleDeck(); // Function to shuffle the deck
    Card^ dealCard(); // Function to deal a card from the deck
};
