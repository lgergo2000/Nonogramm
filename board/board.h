#ifndef BOARD_H
#define BOARD_H

#include "matrix.h"
#include "definition.h"
#include "board.h"


typedef struct
{
    Matrix matrix;
    int number_of_rows, number_of_columns;
    DefinitionList rows, columns;
    DefinitionList definitions;
} Board;


Board InitBoard(DefinitionList d0, DefinitionList d1);

#endif