//
// Created by Alex on 10/27/2021.
//

#ifndef SFML_PROJECT_POKERSCORE_H
#define SFML_PROJECT_POKERSCORE_H
#include <vector>

class PokerScore {


public:
    enum Scores
    {
        Royal_Flush, Straight_Flush, Four_of_a_Kind, Full_House, Flush, Straight, Three_of_a_Kind, Two_Pair, One_Pair, High_Card
    };

    void addScore(Scores score);

    Scores& operator [](unsigned int index);

    int getSize();

private:
    std::vector<Scores> scores;
};


#endif //SFML_PROJECT_POKERSCORE_H
