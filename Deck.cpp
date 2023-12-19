#include "Deck.h"
#include <algorithm>
#include <random>

// Constructor definition
Deck::Deck() {
    cards = gcnew System::Collections::Generic::List<Card^>();
    createDeck();
}

// Function to create a standard deck of cards
void Deck::createDeck() {
    array<System::Char>^ signs = { 'H', 'D', 'C', 'S' }; // Hearts, Diamonds, Clubs, Spades
    const int numCards = 13; // Cards from 1 to 13

    for each (System::Char sign in signs) {
        for (int num = 1; num <= numCards; ++num) {
            Card^ newCard = gcnew Card(num, sign);
            cards->Add(newCard);
        }
    }
}

// Function to shuffle the deck
void Deck::shuffleDeck() {
    System::Random^ rng = gcnew System::Random();
    int n = cards->Count;
    while (n > 1) {
        n--;
        int k = rng->Next(n + 1);
        Card^ temp = cards[k];
        cards[k] = cards[n];
        cards[n] = temp;
    }
}

// Function to deal a card from the deck
Card^ Deck::dealCard() {
    if (cards->Count > 0) {
        Card^ dealtCard = cards[cards->Count - 1];
        cards->RemoveAt(cards->Count - 1);
        return dealtCard;
    }
    return nullptr; // Return null if the deck is empty
}
