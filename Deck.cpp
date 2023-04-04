//
// Created by Alex on 10/26/2021.
//

#include "Deck.h"

Deck::Deck()
{
    deck = new Card[size];
    int k = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 14; j++)
        {
            Card c((RanksENUM)(j), (SuitsENUM)i);
            deck[k] = c;
            k++;
        }
    }

}


std::ostream& operator <<(std::ostream& out, const Deck& deck)
{
    for(int i = 0; i < 52; i++)
    {
        out << deck.deck[i] << std::endl;
    }
    return out;
}


void Deck::shuffle()
{
    srand(time(0));

    for(int i = 0; i < 52; i++)
    {
        int r = i + (rand() % (52 - i));
        swap(i, r);
    }

}

void Deck::swap(int i, int r)
{
    Card temp = deck[i];
    deck[i] = deck[r];
    deck[r] = temp;
}

//Card *Deck::getCard() const {
//    return deck;
//}



