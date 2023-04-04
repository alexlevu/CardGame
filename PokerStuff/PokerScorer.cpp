//
// Created by Alex on 10/28/2021.
//

#include "PokerScorer.h"

PokerScorer::PokerScorer(CardHand ch) : scoreHand(ch)
{

}

bool PokerScorer::isRoyalFlush()
{
    bool suitCheck = false;
    bool rankCheck = false;
    Card card1 = scoreHand.hand[0];
    Card card2 = scoreHand.hand[1];
    Card card3 = scoreHand.hand[2];
    Card card4 = scoreHand.hand[3];
    Card card5 = scoreHand.hand[4];

    if((card1.suit.toString() == card2.suit.toString()) && (card1.suit.toString() == card3.suit.toString()) && (card1.suit.toString() == card4.suit.toString()) && (card1.suit.toString() == card5.suit.toString()))
    {
        suitCheck = true;
    }


    for(int i = 0; i < scoreHand.hand.size(); i++)
    {

        if((scoreHand.hand[i].rank.getRank() == RanksENUM::ACE) && (scoreHand.hand[i+1].rank.getRank() == RanksENUM::TEN) && (scoreHand.hand[i+2].rank.getRank() == RanksENUM::JACK) && (scoreHand.hand[i+3].rank.getRank() == RanksENUM::QUEEN) && (scoreHand.hand[i+4].rank.getRank() == RanksENUM::KING))
        {
            rankCheck = true;
        }
    }

    if(rankCheck && suitCheck)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PokerScorer::isStraightFlush() {
    bool suitCheck = false;
    bool rankCheck = false;
    Card card1 = scoreHand.hand[0];
    Card card2 = scoreHand.hand[1];
    Card card3 = scoreHand.hand[2];
    Card card4 = scoreHand.hand[3];
    Card card5 = scoreHand.hand[4];

    if(isStraight() && isFlush() && !isRoyalFlush())
    {
        return true;
    }
    else
    {
        return false;
    }



}

bool PokerScorer::isFourOfAKind() {
    int counterFour = 0;
    for(int i = 0; i < scoreHand.hand.size(); i++)
    {

        if((scoreHand.hand[i].rank.getRank() == scoreHand.hand[i+1].rank.getRank()) && (scoreHand.hand[i+1].rank.getRank() == scoreHand.hand[i+2].rank.getRank()) && (scoreHand.hand[i+2].rank.getRank() == scoreHand.hand[i+3].rank.getRank()))
        {
            counterFour++;
        }
    }

    if(counterFour > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PokerScorer::isFullHouse() {
    int counterPair = 0;
    int counterThree = 0;
    for(int i = 0; i < scoreHand.hand.size(); i++)
    {
        if((scoreHand.hand[i].rank.getRank() == scoreHand.hand[i+1].rank.getRank()) && (scoreHand.hand[i+1].rank.getRank() != scoreHand.hand[i+2].rank.getRank()))
        {
            counterPair++;
        }

        if((scoreHand.hand[i].rank.getRank() == scoreHand.hand[i+1].rank.getRank()) && (scoreHand.hand[i+1].rank.getRank() == scoreHand.hand[i+2].rank.getRank()))
        {
            counterThree++;
        }
    }


    if(counterPair > 0 && counterThree > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PokerScorer::isFlush() {
    bool suitCheck = false;
    bool rankCheck = false;
    Card card1 = scoreHand.hand[0];
    Card card2 = scoreHand.hand[1];
    Card card3 = scoreHand.hand[2];
    Card card4 = scoreHand.hand[3];
    Card card5 = scoreHand.hand[4];

    if((card1.suit.getSuit() == SuitsENUM::DIAMONDS && card2.suit.getSuit() == SuitsENUM::DIAMONDS && card3.suit.getSuit() == SuitsENUM::DIAMONDS && card4.suit.getSuit() == SuitsENUM::DIAMONDS && card5.suit.getSuit() == SuitsENUM::DIAMONDS) ||
            (card1.suit.getSuit() == SuitsENUM::CLUBS && card2.suit.getSuit() == SuitsENUM::CLUBS && card3.suit.getSuit() == SuitsENUM::CLUBS && card4.suit.getSuit() == SuitsENUM::CLUBS && card5.suit.getSuit() == SuitsENUM::CLUBS) ||
            (card1.suit.getSuit() == SuitsENUM::SPADES && card2.suit.getSuit() == SuitsENUM::SPADES && card3.suit.getSuit() == SuitsENUM::SPADES && card4.suit.getSuit() == SuitsENUM::SPADES && card5.suit.getSuit() == SuitsENUM::SPADES) ||
            (card1.suit.getSuit() == SuitsENUM::HEARTS && card2.suit.getSuit() == SuitsENUM::HEARTS && card3.suit.getSuit() == SuitsENUM::HEARTS && card4.suit.getSuit() == SuitsENUM::HEARTS && card5.suit.getSuit() == SuitsENUM::HEARTS))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PokerScorer::isStraight() {
    int counter = 0;
    for(int i = 0; i < scoreHand.hand.size(); i++)
    {
        if((scoreHand.hand[i].rank.getRank() == scoreHand.hand[i+1].rank.getRank() - 1) && (scoreHand.hand[i+1].rank.getRank() == scoreHand.hand[i+2].rank.getRank() - 1) && (scoreHand.hand[i+2].rank.getRank() == scoreHand.hand[i+3].rank.getRank() - 1) && (scoreHand.hand[i+3].rank.getRank() == scoreHand.hand[i+4].rank.getRank() - 1))
        {
            counter++;
        }
    }

    if(counter > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PokerScorer::isThreeOfAKind() {
    int counter = 0;
    for(int i = 0; i < scoreHand.hand.size(); i++)
    {
        if(scoreHand.hand[i].rank.getRank() == scoreHand.hand[i+1].rank.getRank() && scoreHand.hand[i+1].rank.getRank() == scoreHand.hand[i+2].rank.getRank())
        {
            counter++;
        }
    }

    if(counter > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PokerScorer::isTwoPair() {
    int counter = 0;
    for(int i = 0; i < scoreHand.hand.size(); i++)
    {
        if(scoreHand.hand[i].rank.getRank() == scoreHand.hand[i+1].rank.getRank())
        {
            counter++;
        }
    }

    if(counter > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PokerScorer::isOnePair() {
    int counter = 0;
    for(int i = 0; i < scoreHand.hand.size(); i++)
    {
        if(scoreHand.hand[i].rank.getRank() == scoreHand.hand[i+1].rank.getRank())
        {
            counter++;
        }
    }

    if(counter > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PokerScorer::isHighCard() {
    return true;
}

void numberProbability(double number, double iterations)
{
    double one = 1;
    double total;

    total = iterations / number;

    if(number == 0)
    {
        std::cout << "0 : 0" << std::endl;
    }
    else
    {
        std::cout << one << " : " << total << std::endl;
    }

}

void scoreOneHand()
{
    double highCardCount = 0;
    double royalFlushCount = 0;
    double straightFlushCount = 0;
    double fourOfKindCount = 0;
    double fullHouseCount = 0;
    double flushCount = 0;
    double straightCount = 0;
    double threeOfKindCount = 0;
    double twoPairCount = 0;
    double onePairCount = 0;

    double iterations = 2000000;
    CardHand hand2;

    for(int i = 0; i < iterations; i++)
    {

        PokerScore p = CardHandScorer::scoreHand(hand2);
        hand2.shuffleHand();

        for(int j = 0; j < p.getSize(); j++)
        {
            if(p[j] == PokerScore::Royal_Flush)
            {
                royalFlushCount++;
            }

            if(p[j] == PokerScore::Straight_Flush)
            {
                straightFlushCount++;
            }

            if(p[j] == PokerScore::Four_of_a_Kind)
            {
                fourOfKindCount++;
            }

            if(p[j] == PokerScore::Full_House)
            {
                fullHouseCount++;
            }

            if(p[j] == PokerScore::Flush)
            {
                flushCount++;
            }

            if(p[j] == PokerScore::Straight)
            {
                straightCount++;
            }

            if(p[j] == PokerScore::Three_of_a_Kind)
            {
                threeOfKindCount++;
            }

            if(p[j] == PokerScore::Two_Pair)
            {
                twoPairCount++;
            }

            if(p[j] == PokerScore::One_Pair)
            {
                onePairCount++;
            }

            if(p[j] == PokerScore::High_Card)
            {
                highCardCount++;
            }
        }
    }


    std::cout << "Royal Flushes: ";
    numberProbability(royalFlushCount, iterations);
    std::cout << "Straight Flushes: ";
    numberProbability(straightFlushCount, iterations);
    std::cout << "Four of a Kind: ";
    numberProbability(fourOfKindCount, iterations);
    std::cout << "Full House: ";
    numberProbability(fullHouseCount, iterations);
    std::cout << "Flush: ";
    numberProbability(flushCount, iterations);
    std::cout << "Straight: ";
    numberProbability(straightCount, iterations);
    std::cout << "Three of a Kind: ";
    numberProbability(threeOfKindCount, iterations);
    std::cout << "Two Pairs: ";
    numberProbability(twoPairCount, iterations);
    std::cout << "One Pair: ";
    numberProbability(onePairCount, iterations);
    std::cout << "High Card: ";
    numberProbability(highCardCount, iterations);

}
