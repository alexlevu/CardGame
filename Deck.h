//
// Created by Alex on 10/26/2021.
//

#ifndef SFML_PROJECT_DECK_H
#define SFML_PROJECT_DECK_H
#include <iostream>
#include "Card.h"
#include "RanksENUM.h"
#include "SuitsENUM.h"
#include <vector>
#include <ctime>
#include <cstdlib>

class Deck {
private:


    int size = 52;

public:
    Card *deck;
    Card *getCard() const;
    Deck();
    //Deck(Card* card, int size);

    void shuffle();
    void swap(int i, int r);
    friend std::ostream& operator <<(std::ostream& out, const Deck& deck);
};


#endif //SFML_PROJECT_DECK_H
