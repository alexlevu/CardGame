//
// Created by Alex on 12/2/2021.
//

#include "Screen.h"
#include "Images.h"

Screen::Screen()
{

}

Screen::Screen(ImageName image, std::string title, std::string buttonText, std::string buttonText2, sf::Font& font, sf::Font& font2, sf::Vector2u windowsize) : button(buttonText), back(buttonText2)
{
    //GameScreen
    this->backgroundImage.setTexture(Images::getImage(GAMESCREEN));
    back.setPosition(100, 900);

    //Deck Stuff
    deck = new ImageName[52];
    int k = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = ACES; j < LASTIMAGE; j++)
        {
            deck[k] = static_cast<ImageName>(j);
            k++;
        }
    }

    shuffle();

    for(int i = 0; i < 52; i++)
    {
        linkDeck.push_back(deck[i]);
    }
    this->deckImage.setTexture(Images::getImage(BACK));
    deckImage.setScale(0.39, 0.39);
    deckImage.setPosition(1100, 600);


    //OneSlot stuff
    oneSlot.push(linkDeck.front());
    this->oneSlotImage.setTexture(Images::getImage(oneSlot.top()));
    oneSlotImage.setScale(0.25, 0.25);
    oneSlotImage.setPosition(600, 300);
    linkDeck.pop_front();

    //FiveSlot Stuff
    for(int i = 0; i < 5; i++)
    {
        fiveSlot.push(linkDeck.front());
        linkDeck.pop_front();
    }

    this->fiveSlotImage.setTexture(Images::getImage(BACK));
    fiveSlotImage.setScale(0.39, 0.39);
    fiveSlotImage.setPosition(400, 300);
    //FiveSlot Counter
    fiveSlotCounter.setFont(font2);
    fiveSlotCounter.setFillColor(sf::Color::Red);
    fiveSlotCounter.setCharacterSize(50);
    fiveSlotCounter.setString(std::to_string(fiveSlot.size()));
    fiveSlotCounter.setPosition(455, 240);

    //HandVector
    for(int i = 0; i < 5; i++)
    {
        handVector.push_back(linkDeck.front());
        linkDeck.pop_front();
    }
    this->hand1.setTexture(Images::getImage(handVector[0]));
    hand1.setScale(0.25, 0.25);
    hand1.setPosition(100, 600);

    this->hand2.setTexture(Images::getImage(handVector[1]));
    hand2.setScale(0.25, 0.25);
    hand2.setPosition(300, 600);

    this->hand3.setTexture(Images::getImage(handVector[2]));
    hand3.setScale(0.25, 0.25);
    hand3.setPosition(500, 600);

    this->hand4.setTexture(Images::getImage(handVector[3]));
    hand4.setScale(0.25, 0.25);
    hand4.setPosition(700, 600);

    this->hand5.setTexture(Images::getImage(handVector[4]));
    hand5.setScale(0.25, 0.25);
    hand5.setPosition(900, 600);

    //Count deck after putting out all cards
    deckCounter.setFont(font2);
    deckCounter.setFillColor(sf::Color::Red);
    deckCounter.setCharacterSize(50);
    deckCounter.setString(std::to_string(linkDeck.size()));
    deckCounter.setPosition(1140, 540);

    //Menu
    this->image.setTexture(Images::getImage(image));
    text.setFont(font);
    text.setCharacterSize(100);
    text.setString(title);
    text.setFillColor(sf::Color::Red);

    name.setFont(font2);
    name.setCharacterSize(20);
    name.setString("Alex Vu");
    name.setFillColor(sf::Color::White);
    name.setPosition(0, 0);

    courseName.setFont(font2);
    courseName.setCharacterSize(20);
    courseName.setString("CS 003A");
    courseName.setFillColor(sf::Color::White);
    courseName.setPosition(0, 25);

    crn.setFont(font2);
    crn.setCharacterSize(20);
    crn.setString("#76176");
    crn.setFillColor(sf::Color::White);
    crn.setPosition(0, 45);

    year.setFont(font2);
    year.setCharacterSize(20);
    year.setString("Fall 2021");
    year.setFillColor(sf::Color::White);
    year.setPosition(0, 65);

    this->WinScreen.setTexture(Images::getImage(WINNER));
    WinScreen.setPosition(200, 200);
    disabledState(WIN);

    sf::FloatRect tb = text.getGlobalBounds();
    sf::FloatRect ib = this->image.getGlobalBounds();
    sf::FloatRect bb = button.getGlobalBounds();

    text.setPosition(windowsize.x/2 - tb.width/2, 100);
    tb = text.getGlobalBounds();
    this->image.setPosition(windowsize.x/2 - ib.width/2, 0);
    ib = this->image.getGlobalBounds();
    button.setPosition(windowsize.x/2 - bb.width/2, tb.top + tb.height + 200);
}

void Screen::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(!isEnabled(HIDDEN))
    {
        window.draw(image);
        //draw everything after the background
        window.draw(name);
        window.draw(courseName);
        window.draw(year);
        window.draw(crn);
        window.draw(text);
        window.draw(button);
    }

    else if(isEnabled(HIDDEN))
    {
        window.draw(backgroundImage);
        window.draw(back);
        window.draw(oneSlotImage);

        if(!fiveSlot.empty())
        {
            window.draw(fiveSlotImage);
        }

        window.draw(fiveSlotCounter);
        if(!linkDeck.empty())
        {
            window.draw(deckImage);
        }

        window.draw(deckCounter);

        if(handVector[0] != BACK)
        {
            window.draw(hand1);
        }

        if(handVector[1] != BACK)
        {
            window.draw(hand2);
        }

        if(handVector[2] != BACK)
        {
            window.draw(hand3);
        }

        if(handVector[3] != BACK)
        {
            window.draw(hand4);
        }

        if(handVector[4] != BACK)
        {
            window.draw(hand5);
        }
    }

    else if(isEnabled(WIN))
    {
        window.draw(WinScreen);
    }



}

void Screen::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(!isEnabled(HIDDEN))
    {
        button.eventHandler(window, event);
        button.update();
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
            if(button.getGlobalBounds().contains(mousePos))
            {
                enabledState(HIDDEN);
            }
        }
    }

    else if(isEnabled(HIDDEN))
    {
        back.eventHandler(window, event);
        back.update();
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
            if(back.getGlobalBounds().contains(mousePos))
            {
                disabledState(HIDDEN);
            }

            else if(fiveSlotImage.getGlobalBounds().contains(mousePos))
            {
                if(!fiveSlot.empty())
                {
                    oneSlot.push(fiveSlot.front());
                    fiveSlot.pop();
                }
            }
            else if(hand1.getGlobalBounds().contains(mousePos))
            {
                if(!handVector.empty() && ((handVector[0] == oneSlot.top() - 1) || (handVector[0] == oneSlot.top() + 1) || (handVector[0] == ACES && oneSlot.top() == KINGS) || (handVector[0] == KINGS && oneSlot.top() == ACES)))
                {
                    if(!linkDeck.empty())
                    {
                        oneSlot.push(handVector[0]);
                        handVector[0] = linkDeck.front();
                        linkDeck.pop_front();
                    }
                    else if(linkDeck.empty())
                    {
                        oneSlot.push(handVector[0]);
                        handVector[0] = BACK;
                    }
                    else if(linkDeck.empty() && handVector.empty())
                    {
                        enabledState(WIN);
                    }
                }
            }
            else if(hand2.getGlobalBounds().contains(mousePos))
            {
                if(!handVector.empty() && (handVector[1] == oneSlot.top() - 1) || (handVector[1] == oneSlot.top() + 1) || (handVector[1] == ACES && oneSlot.top() == KINGS) || (handVector[1] == KINGS && oneSlot.top() == ACES))
                {
                    if(!linkDeck.empty())
                    {
                        oneSlot.push(handVector[1]);
                        handVector[1] = linkDeck.front();
                        linkDeck.pop_front();
                    }
                    else if(linkDeck.empty())
                    {
                        oneSlot.push(handVector[1]);
                        handVector[1] = BACK;
                    }
                    else if(linkDeck.empty() && handVector.empty())
                    {
                        enabledState(WIN);
                    }
                }
            }
            else if(hand3.getGlobalBounds().contains(mousePos))
            {
                if(!handVector.empty() && (handVector[2] == oneSlot.top() - 1) || (handVector[2] == oneSlot.top() + 1) || (handVector[2] == ACES && oneSlot.top() == KINGS) || (handVector[2] == KINGS && oneSlot.top() == ACES))
                {
                    if(!linkDeck.empty())
                    {
                        oneSlot.push(handVector[2]);
                        handVector[2] = linkDeck.front();
                        linkDeck.pop_front();
                    }
                    else if(linkDeck.empty())
                    {
                        oneSlot.push(handVector[2]);
                        handVector[2] = BACK;
                    }
                    else if(linkDeck.empty() && handVector.empty())
                    {
                        enabledState(WIN);
                    }
                }
            }
            else if(hand4.getGlobalBounds().contains(mousePos))
            {
                if(!handVector.empty() && (handVector[3] == oneSlot.top() - 1) || (handVector[3] == oneSlot.top() + 1) || (handVector[3] == ACES && oneSlot.top() == KINGS) || (handVector[3] == KINGS && oneSlot.top() == ACES))
                {
                    if(!linkDeck.empty())
                    {
                        oneSlot.push(handVector[3]);
                        handVector[3] = linkDeck.front();
                        linkDeck.pop_front();
                    }
                    else if(linkDeck.empty())
                    {
                        oneSlot.push(handVector[3]);
                        handVector[3] = BACK;
                    }
                    else if(linkDeck.empty() && handVector.empty())
                    {
                        enabledState(WIN);
                    }
                }
            }
            else if(hand5.getGlobalBounds().contains(mousePos))
            {
                if(!handVector.empty() && (handVector[4] == oneSlot.top() - 1) || (handVector[4] == oneSlot.top() + 1) || (handVector[4] == ACES && oneSlot.top() == KINGS) || (handVector[4] == KINGS && oneSlot.top() == ACES))
                {
                    if(!linkDeck.empty())
                    {
                        oneSlot.push(handVector[4]);
                        handVector[4] = linkDeck.front();
                        linkDeck.pop_front();
                    }
                    else if(linkDeck.empty())
                    {
                        oneSlot.push(handVector[4]);
                        handVector[4] = BACK;
                    }
                    else if(linkDeck.empty() && handVector.empty())
                    {
                        enabledState(WIN);
                    }
                }
            }
            else if(oneSlotImage.getGlobalBounds().contains(mousePos))
            {
                if(fiveSlot.empty())
                {
                    int temp = oneSlot.size() - 1;
                    for(int i = 0; i < temp; i++)
                    {
                        fiveSlot.push(oneSlot.top());
                        oneSlot.pop();
                    }
                }
            }
        }
    }
}

void Screen::update()
{

    this->hand1.setTexture(Images::getImage(handVector[0]));
    this->hand2.setTexture(Images::getImage(handVector[1]));
    this->hand3.setTexture(Images::getImage(handVector[2]));
    this->hand4.setTexture(Images::getImage(handVector[3]));
    this->hand5.setTexture(Images::getImage(handVector[4]));

    this->WinScreen.setTexture(Images::getImage(WINNER));

    fiveSlotCounter.setString(std::to_string(fiveSlot.size()));
    this->oneSlotImage.setTexture(Images::getImage(oneSlot.top()));

    deckCounter.setString(std::to_string(linkDeck.size()));
}

void Screen::printDeck()
{
    for(int i = 0; i < 52; i++)
    {
        std::cout << deck[i] << " ";
    }
}

void Screen::shuffle()
{
    srand(time(0));

    for(int i = 0; i < 52; i++)
    {
        int r = i + (rand() % (52 - i));
        swap(i, r);
    }

}

void Screen::swap(int i, int r)
{
    ImageName temp = deck[i];
    deck[i] = deck[r];
    deck[r] = temp;
}
