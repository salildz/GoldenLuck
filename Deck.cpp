#include "Deck.h"


Deck::Deck() {
    for (int i = 1; i < 14; ++i) {
        cards.push_back(Card('H', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards.push_back(Card('D', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards.push_back(Card('C', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards.push_back(Card('S', i));
    }
}


void Deck::shuffleDeck() {
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(std::begin(cards), std::end(cards), rng);
}

void Deck::resetDeck() {
    cards.clear();
    for (int i = 1; i < 14; ++i) {
        cards.push_back(Card('H', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards.push_back(Card('D', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards.push_back(Card('C', i));
    }
    for (int i = 1; i < 14; ++i) {
        cards.push_back(Card('S', i));
    }
}

