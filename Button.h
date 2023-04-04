//
// Created by Alex on 12/2/2021.
//

#ifndef SFML_PROJECT_BUTTON_H
#define SFML_PROJECT_BUTTON_H
#include <SFML/Graphics.hpp>
#include "States.h"

class Button : public sf::Drawable, public States{
private:
    sf::RectangleShape background;
    sf::Text text;
    sf::Font font;
public:
    Button();
    Button(std::string text);
    Button(std::string text, sf::Color color, sf::Color textColor, sf::Vector2f size);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void setPosition(float x, float y);
    sf::FloatRect getGlobalBounds() const;
};


#endif //SFML_PROJECT_BUTTON_H
