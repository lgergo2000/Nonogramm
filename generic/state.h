#ifndef STATE_H
#define STATE_H

#define FILLED 219
#define EMPTY 'X'
#define UNKNOWN ' '

/// @brief state of the board field
/// possible values:
/// FILLED; EMPTY; UNKNOWN
typedef char State;

/// @brief Print the state
/// @param state
void PrintState(State state);

#endif