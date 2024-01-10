#include "Deck.h"

Deck::Deck() { //Creates a normal deck.
    cards = gcnew List<Card^>();

    for (int i = 1; i < 14; ++i) {
        cards->Add(gcnew Card('H', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards->Add(gcnew Card('D', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards->Add(gcnew Card('C', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards->Add(gcnew Card('S', i));
    }

    random = gcnew Random();
}

void Deck::shuffleDeck() { //Randomly shuffles the deck.
    Collections::Generic::List<Card^>^ temp = gcnew Collections::Generic::List<Card^>();

    while (cards->Count > 0) {
        int index = random->Next(cards->Count);
        temp->Add(cards[index]);
        cards->RemoveAt(index);
    }

    cards = temp;
}

void Deck::resetDeck() { //Resets the current deck to a normal deck.
    cards->Clear();

    for (int i = 1; i < 14; ++i) {
        cards->Add(gcnew Card('H', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards->Add(gcnew Card('D', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards->Add(gcnew Card('C', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards->Add(gcnew Card('S', i));
    }
}
