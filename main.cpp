#include <iostream>
#include <SFML/Graphics.hpp>
#include "Card.h"
#include "CardHand.h"
#include "Deck.h"
#include "PokerStuff/PokerScorer.h"
#include "PokerStuff/CardHandScorer.h"
#include "SFMLBackground.h"
#include "SFMLCard.h"
#include "LinkedList.h"
#include <list>
#include <stack>
#include <queue>
#include "Button.h"
#include "Screen.h"

#include "ImageName.h"
#include "Images.h"
int main() {
    sf::RenderWindow window({1280, 1024}, "SFML Project");
    window.setFramerateLimit(60);

    sf::Font font;
    sf::Font font2;
    font.loadFromFile("FFF_Tusj.ttf");
    font2.loadFromFile("OpenSans-Bold.ttf");


    Screen screen(MENU, "One Player Speed", "Start", "Pause", font, font2, window.getSize());
    screen.shuffle();





    //Stack of 1 card for field, middle area
    LinkedList<Card> oneCardStack;
    oneCardStack.pop(); //pop and then grab the value and store into oneCardStack


    //Queue of 5 cards for flips
    LinkedList<Card> fiveCardStack;
    fiveCardStack.pop(); //Pop and then grab the value and store into this queue.

    //Vector of Hand because its easier to find cards
    std::vector<Card> hand;






    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            screen.eventHandler(window, event);

        }

        screen.update();

        window.clear(sf::Color::Cyan);

        window.draw(screen);
        window.display();
    }

}
