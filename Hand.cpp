#include "Hand.h"

Hand::Hand() {
    sum = 0;
    aceCount = 0;
    cards = gcnew List<Card^>();
}

void Hand::addCardToHand(Card^ newCard) {
    cards->Add(newCard);
}

void Hand::setHiddenCard(Card^ newCard) {
    hiddenCard = newCard;
}

Card^ Hand::getHiddenCard() {
    return hiddenCard;
}

void Hand::resetHand() {
    cards->Clear();
}

List<Card^>^ Hand::getHand() {
    return cards;
}

int Hand::getSum() {
    return sum;
}

void Hand::addSum(int add) {
    sum += add;
}

int Hand::getAceCount() {
    return aceCount;
}

void Hand::addAceCount(int add) {
    aceCount += add;
}
