//
// Created by Alex on 10/26/2021.
//

#ifndef SFML_PROJECT_CARDHAND_H
#define SFML_PROJECT_CARDHAND_H
#include "Card.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Deck.h"

class CardHand {
private:

public:
    std::vector<Card> hand;
    CardHand();
    friend std::ostream& operator <<(std::ostream& out, const CardHand& hand);

    void addCard();
    void shuffleHand();
};


#endif //SFML_PROJECT_CARDHAND_H
