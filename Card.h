//
// Created by Alex on 10/6/2021.
//

#ifndef SFML_PROJECT_CARD_H
#define SFML_PROJECT_CARD_H
#include <SFML/Graphics.hpp>
#include "Suit.h"
#include "Rank.h"
#include <iostream>

class Card
{
private:


public:
    Rank rank;
    Suit suit;
    Card();
    Card(RanksENUM rank, SuitsENUM suit);
    friend std::ostream& operator <<(std::ostream& out, const Card& card);

};

void printAllCards();

#endif //SFML_PROJECT_CARD_H
