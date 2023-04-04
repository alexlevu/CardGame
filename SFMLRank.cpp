//
// Created by Alex on 10/31/2021.
//

#include "SFMLRank.h"

SFMLRank::SFMLRank() {

}

SFMLRank::SFMLRank(RanksENUM rank) {
    if(rank == ACE)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("A");
        text.setPosition(12, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == TWO)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("2");
        text.setPosition(12, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == THREE)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("3");
        text.setPosition(12, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == FOUR)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("4");
        text.setPosition(12, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == FIVE)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("5");
        text.setPosition(12, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == SIX)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("6");
        text.setPosition(12, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == SEVEN)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("7");
        text.setPosition(12, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == EIGHT)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("8");
        text.setPosition(12, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == NINE)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("9");
        text.setPosition(12, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == TEN)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("10");
        text.setPosition(10, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == JACK)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("J");
        text.setPosition(14, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == QUEEN)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("Q");
        text.setPosition(12, 15);
        text.setFillColor(sf::Color::Black);
    }
    if(rank == KING)
    {
        font.loadFromFile("OpenSans-Bold.ttf");
        text.setFont(font);
        text.setString("K");
        text.setPosition(12, 15);
        text.setFillColor(sf::Color::Black);
    }
}

void SFMLRank::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states = getTransform();
    window.draw(text, states);
}
