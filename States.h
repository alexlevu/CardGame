//
// Created by Alex on 12/2/2021.
//

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H
#include "StatesEnum.h"

class States {
private:
    bool states[LAST];

public:
    bool isEnabled(StateEnum state) const;
    void enabledState(StateEnum state);
    void disabledState(StateEnum state);
};


#endif //SFML_PROJECT_STATES_H
