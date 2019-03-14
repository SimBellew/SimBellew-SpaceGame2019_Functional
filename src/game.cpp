#include "game.hpp"
#include <fstream>

// Load state
// - Only loads test state
state::State *LoadState(YAML::Node state)
{
    return new state::State(ships::LoadShip(state, NULL));
}

// Main game recursion
// - Modifies the 'next_ship' and then re-makes
//   the game_state.
state::State *StepGame(state::State *game_state)
{
    // Print state
    PrintShipStatus(*game_state -> next_ship);

    // Recursive state modifier - Tail-recursion + Move semantics (rvalue)
    return StepGame(new state::State(game_state, TakeAction(*game_state -> next_ship)));
}

static const std::string Actions[] = {"Query", "Action", "Skip"};
// Take action
// - Prints possible actions.
// - Enacts action
ships::Ship *TakeAction(const ships::Ship &ship)
{
    PrintActions(ship, 0);

    int int_action;
    std::vector<ships::Ship> affected_ships = std::vector<ships::Ship> {};

    std::cin >> int_action;

    switch (int_action) {
        case 0: RunQuery(); break;
        case 1: affected_ships = ShipAction(ship); break;
        case 2: affected_ships = SkipAction(ship); break;
    }

    // TODO: implement rest of this work
}

static const std::string Queries[] = {"List enemies", "List friendlies", "Back"};
void RunQuery()
{
    // TODO: implement queries
}

std::vector<ships::Ship> SkipAction(const ships::Ship &ship)
{
    std::vector<ships::Ship> ships;
    ships::Ship skipped_ship = ships::Ship(ship, "Skip");

    ships.push_back(ships::Ship(skipped_ship));
}

// Take Ship Action
// - Prints possible ship actions.
// - Enacts action
std::vector<ships::Ship> ShipAction(const ships::Ship &ship)
{
    // Print actions
    std::cout << ship.name << " has the following actions:" << std::endl;
    PrintShipActions(ship, 0);

    // TODO - enact action
    int int_action;
    std::cin >> int_action;

    return std::vector<ships::Ship> { };
}

// Run queries
// - Recursively prints avaliable queries
void RunQuery(const ships::Ship &ship, int int_query)
{
    std::string query = Queries[int_query];

    std::cout << "  " << int_query << ": " << query << std::endl;

    if (query != "Back") PrintActions(ship, int_query + 1);
}

// Print action
// - Recursively prints avaliable actions
void PrintActions(const ships::Ship &ship, int int_action)
{
    std::string action = Actions[int_action];

    if (ships::TestShipAction(ship, action)) std::cout << "  " << int_action << ": " << action << std::endl;

    if (action != "Skip") PrintActions(ship, int_action + 1);
}

// Print action
// - Recursively prints avaliable ship actions
void PrintShipActions(const ships::Ship &ship, int int_ship_action)
{
    std::string action = ships::ActionStrings[int_ship_action];

    if (ships::TestShipAction(ship, action)) std::cout << "  " << int_ship_action << ": " << action << std::endl;

    if (action != "Back") PrintShipActions(ship, int_ship_action + 1);
}

// Prints ship status
void PrintShipStatus(const ships::Ship &ship)
{
    std::cout << "Ship " << ship.name << " has the following stats:" << std::endl;
    std::cout << "  Action points: " << ship.stats -> AP << std::endl;
    std::cout << "  Energy points: " << ship.stats -> EP << std::endl;
    std::cout << "  Velocity: " << ship.stats -> velocity.as_string() << std::endl;
    std::cout << "  Facing: " << ship.stats -> facing.as_string() << std::endl;
}