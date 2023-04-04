//
// Created by Alex on 10/31/2021.
//

#include "SFMLSuit.h"


SFMLSuit::SFMLSuit() {

}

SFMLSuit::SFMLSuit(Suit baseSuit) {

}

void SFMLSuit::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states = getTransform();
    window.draw(sprite, states);
    window.draw(sprite2, states);
}

SFMLSuit::SFMLSuit(SuitsENUM suit) {

    if(suit == DIAMONDS)
    {
        texture.loadFromFile("diamonds.png");
        sprite.setTexture(texture);
        sprite2.setTexture(texture);
        sprite.setScale(0.07, 0.07);
        sprite2.setScale(0.07, 0.07);

        sprite.setPosition(0, 0);
        sprite2.setPosition(32, 58);
    }
    if(suit == HEARTS)
    {
        texture.loadFromFile("heart.png");
        sprite.setTexture(texture);
        sprite2.setTexture(texture);
        sprite.setScale(0.3, 0.3);
        sprite2.setScale(0.3, 0.3);

        sprite.setPosition(0, 0);
        sprite2.setPosition(50, 70);
        sprite2.rotate(180);
    }
    if(suit == SPADES)
    {
        texture.loadFromFile("spades.png");
        sprite.setTexture(texture);
        sprite2.setTexture(texture);
        sprite.setScale(0.03, 0.03);
        sprite2.setScale(0.03, 0.03);

        sprite.setPosition(0, 0);
        sprite2.setPosition(50, 70);
        sprite2.rotate(180);
    }

    if(suit == CLUBS)
    {
        texture.loadFromFile("club.png");
        sprite.setTexture(texture);
        sprite2.setTexture(texture);

        sprite.setScale(0.2, 0.2);
        sprite2.setScale(0.2, 0.2);

        sprite.setPosition(0, 0);
        sprite2.setPosition(50, 70);
        sprite2.rotate(180);
    }
}
