#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include "ship.hpp"
#include "state.hpp"

state::State *LoadState(YAML::Node state);
state::State *StepGame(state::State *game_state);
ships::Ship *TakeAction(const ships::Ship &ship);
std::vector<ships::Ship> SkipAction(const ships::Ship &ship);
std::vector<ships::Ship> ShipAction(const ships::Ship &ship);

void PrintActions(const ships::Ship &ship, int int_action);
void PrintShipActions(const ships::Ship &ship, int int_ship_action);
void PrintShipStatus(const ships::Ship &ship);

static const std::vector<std::string> events = std::vector<std::string> { "main_query, main_action, main_skip, action_accel, action_rotate, action_fire" };

#endif /* GAME_H_ */