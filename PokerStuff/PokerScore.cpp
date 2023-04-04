//
// Created by Alex on 10/27/2021.
//

#include "PokerScore.h"

void PokerScore::addScore(Scores score)
{
    scores.push_back(score);
}

PokerScore::Scores &PokerScore::operator[](unsigned int index) {
    return scores[index];
}

int PokerScore::getSize() {
    return scores.size();
}
