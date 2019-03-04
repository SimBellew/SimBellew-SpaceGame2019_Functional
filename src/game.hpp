#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <iostream>
#include "ship.hpp"
#include "state.hpp"

state::State *LoadState(std::string folder);
state::State *StepGame(state::State *game_state);
void PrintShipStatus(ships::Ship *ship);
ships::Ship *TakeAction(ships::Ship *ship);
void PrintActions(ships::Ship *ship, int int_action);

#endif /* GAME_H_ */