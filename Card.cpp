#include "Card.h"
#include <iostream>

// Constructor definition
Card::Card() {
    cardNum = 0;
    cardSign = ' ';
}

// Constructor with parameters definition
Card::Card(int num, char sign) {
    cardNum = num;
    cardSign = sign;
}

// Getter for cardNum
int Card::getCardNum() {
    return cardNum;
}

// Setter for cardNum
void Card::setCardNum(int num) {
    cardNum = num;
}

// Getter for cardSign
char Card::getCardSign() {
    return cardSign;
}

// Setter for cardSign
void Card::setCardSign(char sign) {
    cardSign = sign;
}

// Function to display card details
Card^ Card::getCard() {
    return this;
}