//
// Created by Alex on 10/25/2021.
//

#ifndef SFML_PROJECT_SUIT_H
#define SFML_PROJECT_SUIT_H
#include "SuitsENUM.h"
#include <string>
class Suit {
private:
    SuitsENUM suit;

public:
    Suit();
    Suit(SuitsENUM suit);
    SuitsENUM getSuit() const;
    std::string toString() const;
    void setSuit(SuitsENUM suit);


};


#endif //SFML_PROJECT_SUIT_H
