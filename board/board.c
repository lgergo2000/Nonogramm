#include "board.h"

Board InitBoard(DefinitionList d0, DefinitionList d1)
{
    Board board;

    if(d0.length < d1.length)
    {
        board.rows = d0;
        board.columns = d1;
    }
    else
    {
        board.rows = d1;
        board.columns = d0;
    }
    board.number_of_rows = board.rows.length;
    board.number_of_columns = board.columns.length;

    board.definitions = InitDefinitionList(board.rows.length + board.columns.length);
    int row_index = 0, column_index = 0;
    for (int i = 0; i < board.rows.length + board.columns.length; i++)
    {
        if(i%2 == 0 && (int)(i/2) < board.rows.length)
        {
            board.definitions.data[i] = board.rows.data[row_index++];
        }
        else
        {
            board.definitions.data[i] = board.columns.data[column_index++];
        }
    }

    board.matrix = MatrixInit(board.number_of_rows, board.number_of_columns);
    for (int i = 0; i < board.number_of_rows; i++)
    {
        for (int j = 0; j < board.number_of_columns; j++)
        {
            board.matrix.data[i][j] = UNKNOWN;
        }
    }


    return board;
}