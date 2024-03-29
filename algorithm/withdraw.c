#include "withdraw.h"
#include "fill_matrix_with_vector.h"

void WithdrawDefinition(Board* board, Vector* tmp)
{
    for (int i = 0; i < board->matrix.rows; i++)
    {
        for (int j = 0; j < board->matrix.columns; j++)
        {
            board->matrix.data[i][j] = UNKNOWN;
        }
    }

    for (int i = 0; i < board->definitions.length; i++)
    {
        if(board->definitions.data[i].index == -1) continue;
        FillMatrixWithVectorIfPossible(&(board->matrix), &(board->definitions.data[i].possible_vectors.data[board->definitions.data[i].index]), i, tmp);
    }

}