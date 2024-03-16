#include "solver.h"
#include "fill_matrix_with_vector.h"
#include "withdraw.h"


void SolveBoard(Board* board)
{
    int main_index = 0;
    while (TRUE)
    {
        int set = -1;
        // iterates thought the possible vectors
        for (int definitions_sub_index = board->definitions.data[main_index].index + 1; definitions_sub_index < board->definitions.data[main_index].possible_vectors.length; definitions_sub_index++)
        {
            Vector current_possible_vector = board->definitions.data[main_index].possible_vectors.data[definitions_sub_index];
            set = FillMatrixWithVectorIfPossible(&(board->matrix), current_possible_vector, main_index);
            if(set == 1)
            {
                board->definitions.data[main_index].index = definitions_sub_index;
                break;
            }
        }
        if(set == 1)
        {
            main_index++;
            if(main_index == board->definitions.length)
            {
                printf("Result:\n");
                PrintMatrix(board->matrix);
                break;
            }
        }
        else if(set == -1)
        {
            if(main_index == 0)
            {
                printf("No solution\n");
                break;
            }
            WithdrawDefinition(&(board->matrix), --main_index);
            board->definitions.data[main_index+1].index = -1;
        }
    }
}