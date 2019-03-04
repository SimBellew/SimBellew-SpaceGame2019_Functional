#ifndef STATE_H_
#define STATE_H_

#include "ship.hpp"

namespace state
{
    int begin();

    struct State
    {
        ships::Ship *next_ship;

        State() { }
        State(ships::Ship *ship) { next_ship = ship; }
        State(State *old_state, ships::Ship *ship) { next_ship = ship; delete old_state; }
    };
}

#endif /* STATE_H_ */