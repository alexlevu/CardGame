//
// Created by Alex on 10/31/2021.
//

#ifndef SFML_PROJECT_SFMLSUIT_H
#define SFML_PROJECT_SFMLSUIT_H
#include "Suit.h"
#include <SFML/Graphics.hpp>

class SFMLSuit : public sf::Drawable, public sf::Transformable{
private:
    Suit baseSuit;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite sprite2;
public:
    SFMLSuit();
    SFMLSuit(Suit baseSuit);
    SFMLSuit(SuitsENUM suit);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_SFMLSUIT_H
