#undef VERBOSE
#include "solver.h"
#include "fill_matrix_with_vector.h"
#include "withdraw.h"
// #include "definition.h"

typedef struct
{
    int index;
    int possible_vector_length;
} VectorLengthDict;


void SolveBoard(Board* board)
{
    int iter_index = 0;
    int main_index;
#ifdef VERBOSE
    int cnt = 0;
#endif

    VectorLengthDict* vector_length_dict = (VectorLengthDict*)calloc(board->definitions.length, sizeof(VectorLengthDict));
    for (int i = 0; i < board->definitions.length; i++)
    {
        vector_length_dict[i] = (VectorLengthDict) {i, board->definitions.data[i].possible_vectors.length};
    }

    for (int i = 0; i < board->definitions.length - 1; ++i)
    {
        for (int j = 0; j < board->definitions.length - i - 1; ++j)
        {
            if (vector_length_dict[j].possible_vector_length > vector_length_dict[j+1].possible_vector_length)
            {
                VectorLengthDict vector_length_dict_tmp = vector_length_dict[j];

                vector_length_dict[j] = vector_length_dict[j+1];
                vector_length_dict[j+1] = vector_length_dict_tmp;
            }
        }
    }

    Vector tmp;
    if(board->number_of_columns > board->number_of_rows) tmp = InitVector(board->number_of_columns);
    else tmp = InitVector(board->number_of_rows);
    while (TRUE)
    {
        int set = -1;
        main_index = vector_length_dict[iter_index].index;
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
                if(iter_index > ((float)max*2)/3)
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
            iter_index++;
            if(iter_index == board->definitions.length)
            {
                printf("Result:\n");
                for (int i = 0; i < board->matrix.rows; i++)
                {
                    for (int j = 0; j < board->matrix.columns; j++)
                    {
                        if(board->matrix.data[i][j] == EMPTY) board->matrix.data[i][j] = UNKNOWN;
                    }
                }
                PrintMatrix(board->matrix);
                break;
            }
        }
        else if(set == -1)
        {
            if(iter_index == 0)
            {
                printf("No solution\n");
                break;
            }
            board->definitions.data[main_index].index = -1;
            main_index = vector_length_dict[--iter_index].index;
            int tmp_index = board->definitions.data[main_index].index;
            board->definitions.data[main_index].index = -1;
            WithdrawDefinition(board, &tmp);
            board->definitions.data[main_index].index = tmp_index;

        }
    }
}