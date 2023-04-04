//
// Created by Alex on 10/27/2021.
//

#ifndef SFML_PROJECT_CARDHANDSCORER_H
#define SFML_PROJECT_CARDHANDSCORER_H
#include "PokerScore.h"
#include "../CardHand.h"
#include "PokerScorer.h"

class CardHandScorer{
public:
    static PokerScore scoreHand(CardHand ch);
};


#endif //SFML_PROJECT_CARDHANDSCORER_H
