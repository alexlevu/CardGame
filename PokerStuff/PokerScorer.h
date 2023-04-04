//
// Created by Alex on 10/28/2021.
//

#ifndef SFML_PROJECT_POKERSCORER_H
#define SFML_PROJECT_POKERSCORER_H
#include "../CardHand.h"
#include "PokerScore.h"
#include "CardHandScorer.h"
#include <SFML/Graphics.hpp>
class PokerScorer {
private:
    CardHand scoreHand;
public:

    PokerScorer(CardHand ch);


    bool isRoyalFlush();
    bool isStraightFlush();
    bool isFourOfAKind();
    bool isFullHouse();
    bool isFlush();
    bool isStraight();
    bool isThreeOfAKind();
    bool isTwoPair();
    bool isOnePair();
    bool isHighCard();


};

void scoreOneHand();
void numberProbability(double number, double iterations);
#endif //SFML_PROJECT_POKERSCORER_H
