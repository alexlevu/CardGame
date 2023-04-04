//
// Created by Alex on 10/26/2021.
//

#include "CardHand.h"

CardHand::CardHand() // Working on how to make cards not repeat
{

    Deck deck;

//    hand.push_back(Card(ACE, DIAMONDS));
//    hand.push_back(Card(TWO, DIAMONDS));
//    hand.push_back(Card(THREE, DIAMONDS));
//    hand.push_back(Card(FOUR, DIAMONDS));
//    hand.push_back(Card(FIVE, DIAMONDS));

    srand(time(0));


    for(int i = 0; i < 5; i++)
    {
        int randomNumber = rand() % 52;
        hand.push_back(deck.deck[randomNumber]);
    }





    for(int x = 1; x < hand.size(); x++)
    {
        for(int i = 1; i < hand.size(); i++)
        {
            Card temp;
            if(hand[i].rank.getRank() < hand[i-1].rank.getRank())
            {
                temp = hand[i];
                hand[i] = hand[i-1];
                hand[i-1] = temp;
            }
        }
    }


}

std::ostream& operator <<(std::ostream& out, const CardHand& hand)
{
    for(int i = 0; i < hand.hand.size(); i++)
    {
        out << hand.hand[i] << std::endl;
    }
    return out;
}

void CardHand::shuffleHand()
{
    Deck deck;

    for(int i = 0; i < 5; i++)
    {
        hand.clear();
    }

    for(int i = 0; i < 5; i++)
    {
        //srand(time(0));
        int randomNumber = rand() % 52;
        hand.push_back(deck.deck[randomNumber]);
    }
}

void CardHand::addCard()
{

}