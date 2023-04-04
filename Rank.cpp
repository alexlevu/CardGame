//
// Created by Alex on 10/25/2021.
//

#include "Rank.h"

Rank::Rank() {

}

Rank::Rank(RanksENUM rank) :rank(rank) {

}

std::string Rank::toString() const
{
    std::string r[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    return r[rank-1];
}

std::string Rank::toShortString() const
{
    if(rank > 1 && rank < 11)
    {
        return std::to_string((int)rank);
    }
    else
    {
        return ""+toString()[0];
    }
}

int Rank::toInt() {
    return 0;
}

RanksENUM Rank::getRank() const {
    return rank;
}

void Rank::setRank(RanksENUM rank) {
    Rank::rank = rank;
}

