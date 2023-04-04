//
// Created by Alex on 10/31/2021.
//

#ifndef SFML_PROJECT_SFMLRANK_H
#define SFML_PROJECT_SFMLRANK_H
#include "Rank.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class SFMLRank : public sf::Drawable, public sf::Transformable{
private:
    sf::Text text;
    sf::Font font;
public:
    SFMLRank();
    SFMLRank(RanksENUM rank);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_SFMLRANK_H
