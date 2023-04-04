//
// Created by Alex on 12/2/2021.
//

#include "Button.h"

Button::Button() : Button("Ok", sf::Color::White, sf::Color::Blue, {100, 50}){

}

Button::Button(std::string text) : Button(text, sf::Color::White, sf::Color::Blue, {100, 50}){

}

Button::Button(std::string text, sf::Color color, sf::Color textColor, sf::Vector2f size) {
    font.loadFromFile("OpenSans-Bold.ttf");
    this->text.setFont(font);
    this->text.setFillColor(textColor);
    this->text.setString(text);
    //this->background.setPosition(100, 100); //Set position of the background of the button, so basically moving the button

    background.setSize(size);
    background.setFillColor(color);

    sf::FloatRect tb = this->text.getGlobalBounds();
    sf::FloatRect bb = background.getGlobalBounds();

    this->text.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height/2 - 5);
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = background.getTransform();
    window.draw(background);
    window.draw(text, states);
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(background.getGlobalBounds().contains(mousePos))
    {
        enabledState(HOVERED);
    }
    else
    {
        disabledState(HOVERED);
    }
}

void Button::update()
{
    if(isEnabled(HOVERED))
    {
        //text.setScale(1 , 1);
        text.setFillColor(sf::Color::Red);

        //background.setScale(1.5, 1.5);

    }
    else if(!isEnabled(HOVERED))
    {
        //text.setScale(1 , 1);
        text.setFillColor(sf::Color::Black);
        //background.setScale(1, 1);
    }
}

sf::FloatRect Button::getGlobalBounds() const
{
    return background.getGlobalBounds();
}

void Button::setPosition(float x, float y)
{
    background.setPosition(x, y);
}
