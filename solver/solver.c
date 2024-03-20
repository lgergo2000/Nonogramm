#undef VERBOSE
#include "solver.h"
#include "fill_matrix_with_vector.h"
#include "withdraw.h"

void SolveBoard(Board* board)
{
    int main_index = 0;
#ifdef VERBOSE
    int cnt = 0;
#endif
    Vector tmp;
    if(board->number_of_columns > board->number_of_rows) tmp = InitVector(board->number_of_columns);
    else tmp = InitVector(board->number_of_rows);
    while (TRUE)
    {
        int set = -1;
        // iterates thought the possible vectors
        for (int definitions_sub_index = board->definitions.data[main_index].index + 1; definitions_sub_index < board->definitions.data[main_index].possible_vectors.length; definitions_sub_index++)
        {
            set = FillMatrixWithVectorIfPossible(&(board->matrix), &(board->definitions.data[main_index].possible_vectors.data[definitions_sub_index]), main_index, &tmp);
            if(set == 1)
            {
#ifdef VERBOSE
                int max;
                if(board->number_of_columns > board->number_of_rows) max = board->number_of_columns;
                else max = board->number_of_rows;
                if(main_index > ((float)max*2)/3)
                {
                    printf("Possible solution found: %d\n", cnt++);
                    PrintMatrix(board->matrix);
                    printf("\n");
                }
#endif
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