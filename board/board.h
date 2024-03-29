#ifndef BOARD_H
#define BOARD_H

#include "matrix.h"
#include "definition.h"
#include "board.h"


/// @brief
/// @param matrix Matrix
/// @param number_of_rows int
/// @param number_of_columns int
/// @param rows DefinitionList
/// @param columns DefinitionList
/// @param definitions DefinitionList
typedef struct
{
    Matrix matrix;
    int number_of_rows, number_of_columns;
    DefinitionList rows, columns;
    DefinitionList definitions;
} Board;


/// @brief Initialize a board based on the d0 and d1 DefinitionList
/// @param d0 column definition list
/// @param d1 row definition list
/// @return empty board
Board InitBoard(DefinitionList d0, DefinitionList d1);

#endif