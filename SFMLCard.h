//
// Created by Alex on 10/31/2021.
//

#ifndef SFML_PROJECT_SFMLCARD_H
#define SFML_PROJECT_SFMLCARD_H
#include <SFML/Graphics.hpp>
#include "Rank.h"
#include "Suit.h"
#include "SFMLBackground.h"
#include "SFMLRank.h"
#include "SFMLSuit.h"

class SFMLCard : public sf::Drawable{
private:
    SFMLBackground sfmlBackground;
    SFMLRank sfmlRank;
    SFMLSuit sfmlSuit;
public:
    SFMLCard();
    SFMLCard(RanksENUM rank, SuitsENUM suit);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(float x, float y);
};


#endif //SFML_PROJECT_SFMLCARD_H
