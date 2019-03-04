#include "game.hpp"

// Load state
// - Only loads test state
state::State *LoadState(std::string folder)
{
    std::string file = folder + "/ship_one.yaml";
    return new state::State(ships::LoadShip(file, NULL));
}

// Main game recursion
// - Modifies the 'next_ship' and then re-makes
//   the game_state.
state::State *StepGame(state::State *game_state)
{
    // Print state
    PrintShipStatus(game_state -> next_ship);

    // Recursive state modifier - Tail-recursion + Move semantics (rvalue)
    return StepGame(new state::State(game_state, TakeAction(game_state -> next_ship)));
}

// Take action
// - Prints possible actions.
// - Enacts action
ships::Ship *TakeAction(ships::Ship *ship)
{
    // Print actions
    PrintActions(ship, 0);

    // TODO - enact action
    int int_action;
    std::cin >> int_action;

    return ship;
}

// Print action
// - Recursively prints avaliable actions
void PrintActions(ships::Ship *ship, int int_action)
{
    ships::Actions action = ships::Actions::Accelerate;

    try
    {
        action = static_cast<ships::Actions>(int_action); // TEST THIS
    }
    catch (...)
    {
        return;
    }

    if(ships::TestAction(ship, action))
    {
        std::cout << int_action << ": " << action << std::endl;
    }

    PrintActions(ship, action + 1);
}

// Prints ship status
void PrintShipStatus(ships::Ship *ship)
{
    std::cout << "Ship " << ship -> name << " has:" << std::endl;
    std::cout << "  Action points: " << ship -> stats -> AP << std::endl;
    std::cout << "  Energy points: " << ship -> stats -> EP << std::endl;
    std::cout << "  Velocity: " << ship -> stats -> velocity.as_string() << std::endl;
    std::cout << "  Facing: " << ship -> stats -> facing.as_string() << std::endl;
}