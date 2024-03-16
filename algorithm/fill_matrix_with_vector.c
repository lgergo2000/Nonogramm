#include "fill_matrix_with_vector.h"

/// @brief Replace a given vector in a matrix
/// @param matrix Matrix*
/// @param vector Vector
/// @param definition_index int
void ReplaceVectorInMatrix(Matrix* matrix, Vector vector, int definition_index)
{
    if(IsRow(*matrix, definition_index))
    {
        if(matrix->columns != vector.length) return;
        for (int i = 0; i < vector.length; i++)
        {
            matrix->data[GetRowIndex(*matrix, definition_index)][i] = vector.data[i];
        }
    }
    else
    {
        if(matrix->rows != vector.length) return;
        for (int i = 0; i < vector.length; i++)
        {
            matrix->data[i][GetColumnIndex(*matrix, definition_index)] = vector.data[i];
        }
    }
}


/// @brief Selects a vector from a matrix with a definition index
/// @param matrix Matrix
/// @param definition_index int
/// @return
Vector SelectVectorFromMatrixWithDefinitonIndex(Matrix matrix, int definition_index)
{
    if(IsRow(matrix, definition_index))
    {
        return(SelectVectorFromMatrix(matrix, GetRowIndex(matrix, definition_index), TRUE));
    }
    else
    {
        return(SelectVectorFromMatrix(matrix, GetColumnIndex(matrix, definition_index), FALSE));
    }
}

int FillMatrixWithVectorIfPossible(Matrix* matrix, Vector vector, int definition_index)
{
    Vector tmp = SelectVectorFromMatrixWithDefinitonIndex(*matrix, definition_index);
    for (int i = 0; i < vector.length; i++)
    {
        if(!(vector.data[i] == tmp.data[i] || tmp.data[i] == UNKNOWN)) return -1;
    }

    ReplaceVectorInMatrix(matrix, vector, definition_index);
    return 1;
}