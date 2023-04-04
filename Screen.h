//
// Created by Alex on 12/2/2021.
//

#ifndef SFML_PROJECT_SCREEN_H
#define SFML_PROJECT_SCREEN_H
#include <SFML/Graphics.hpp>
#include "ImageName.h"
#include "Button.h"
#include <stack>
#include <list>
#include <queue>
#include "Card.h"
#include <vector>

class Screen : public sf::Drawable, public States{
private:
    //GameScreen
    sf::Text deckCounter;
    sf::Text fiveSlotCounter;


    ImageName *deck; //Creates the deck
    std::list<ImageName> linkDeck;//Creates Link list deck
    std::vector<ImageName> handVector;

    std::stack<ImageName> oneSlot;
    std::queue<ImageName> fiveSlot;

    sf::Sprite backgroundImage;
    sf::Sprite oneSlotImage;
    sf::Sprite fiveSlotImage;
    sf::Sprite deckImage;

    sf::Sprite hand1;
    sf::Sprite hand2;
    sf::Sprite hand3;
    sf::Sprite hand4;
    sf::Sprite hand5;

    sf::Sprite WinScreen;
    Button back;

    //Menu
    sf::Text text;
    sf::Text name;
    sf::Text courseName;
    sf::Text crn;
    sf::Text year;

    sf::Sprite image;
    Button button;
public:
    Screen();
    Screen(ImageName image, std::string title, std::string buttonText, std::string buttonText2, sf::Font& font, sf::Font& font2, sf::Vector2u windowsize);
    void eventHandler(sf::RenderWindow& window, sf::Event event);

    void printDeck();
    void swap(int i, int r);
    void shuffle();
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_SCREEN_H
