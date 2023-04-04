//
// Created by Alex on 10/25/2021.
//

#ifndef SFML_PROJECT_RANK_H
#define SFML_PROJECT_RANK_H
#include "RanksENUM.h"
#include <string>
class Rank{
private:
    RanksENUM rank;
public:
    RanksENUM getRank() const;

    void setRank(RanksENUM rank);

public:
    Rank();
    Rank(RanksENUM rank);

    std::string toString() const;
    std::string toShortString() const;
    int toInt();


};

#endif //SFML_PROJECT_RANK_H
