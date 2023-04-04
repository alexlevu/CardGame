//
// Created by Alex on 12/2/2021.
//

#include "States.h"

bool States::isEnabled(StateEnum state) const
{
    return states[state];
}

void States::enabledState(StateEnum state) {

    states[state] = true;
}

void States::disabledState(StateEnum state) {

    states[state] = false;
}
