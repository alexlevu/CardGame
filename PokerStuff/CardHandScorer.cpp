//
// Created by Alex on 10/27/2021.
//

#include "CardHandScorer.h"

PokerScore CardHandScorer::scoreHand(CardHand ch) {
    PokerScore score;
    PokerScorer ps(ch);

    if(ps.isRoyalFlush())
    {
        score.addScore(PokerScore::Royal_Flush);
    }

    if(ps.isStraightFlush())
    {
        score.addScore(PokerScore::Straight_Flush);
    }

    if(ps.isFourOfAKind())
    {
        score.addScore(PokerScore::Four_of_a_Kind);
    }

    if(ps.isFullHouse())
    {
        score.addScore(PokerScore::Full_House);
    }

    if(ps.isFlush())
    {
        score.addScore(PokerScore::Flush);
    }

    if(ps.isStraight())
    {
        score.addScore(PokerScore::Straight);
    }

    if(ps.isThreeOfAKind())
    {
        score.addScore(PokerScore::Three_of_a_Kind);
    }

    if(ps.isTwoPair())
    {
        score.addScore(PokerScore::Two_Pair);
    }

    if(ps.isOnePair())
    {
        score.addScore(PokerScore::One_Pair);
    }

    if(ps.isHighCard())
    {
        score.addScore(PokerScore::High_Card);
    }

    return score;
}
