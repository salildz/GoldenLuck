#include "Card.h"

#include <iostream>

// Constructor definition
Card::Card() {
    cardNum = 0;
    cardSign = ' ';
}

// Constructor with parameters definition
Card::Card(int num, System::Char sign) {
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
System::Char Card::getCardSign() {
    return cardSign;
}

// Setter for cardSign
void Card::setCardSign(System::Char sign) {
    cardSign = sign;
}

// Function to display card details
void Card::displayCard() {
    System::Console::WriteLine("Card Number: {0}, Card Sign: {1}", cardNum, cardSign);
}