//
// Created by Alex on 10/6/2021.
//

#include "Card.h"


Card::Card()
{

}

Card::Card(RanksENUM rank, SuitsENUM suit) : rank(rank), suit(suit)
{

}

std::ostream& operator <<(std::ostream& out, const Card& card)
{
    out << card.rank.toString() << " of " << card.suit.toString();
    return out;
}

void printAllCards()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 14; j++)
        {
            Card c((RanksENUM)(j), (SuitsENUM)i);
            std::cout << c << std::endl;
        }
    }
    std::cout << "----------------" << std::endl;
}

