//
// Created by Alex on 10/31/2021.
//

#include "SFMLCard.h"

SFMLCard::SFMLCard() {

}

SFMLCard::SFMLCard(RanksENUM rank, SuitsENUM suit) : sfmlRank(rank), sfmlSuit(suit){

    sfmlBackground.setSize({50, 75});
    sfmlBackground.setFillColor(sf::Color::White);
    sfmlBackground.setPosition(100, 100);
}

void SFMLCard::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(sfmlBackground);
    window.draw(sfmlRank);
    window.draw(sfmlSuit);
}

void SFMLCard::setPosition(float x, float y) {
    sfmlBackground.setPosition(x, y);
    sfmlSuit.setPosition(x, y);
    sfmlRank.setPosition(x, y);
}
