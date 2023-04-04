//
// Created by Alex on 10/25/2021.
//

#include "Suit.h"

SuitsENUM Suit::getSuit() const {
    return suit;
}

void Suit::setSuit(SuitsENUM suit) {
    Suit::suit = suit;
}

std::string Suit::toString() const
{
    std::string s[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    return s[suit];
}

Suit::Suit() {

}

Suit::Suit(SuitsENUM suit) : suit(suit){

}
