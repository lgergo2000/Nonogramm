#include "matrix.h"

Matrix MatrixInit(int rows, int columns)
{
    Matrix matrix;
    matrix.rows = rows;
    matrix.columns = columns;
    matrix.data = (State**)malloc(rows * sizeof(State*));
    for (int i = 0; i < rows; i++)
    {
        matrix.data[i] = (State*)calloc(rows, sizeof(State));
    }

    return matrix;
}

void MatrixFree(Matrix* matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        free(matrix->data[i]);
    }
    free(matrix->data);
}


Vector SelectVectorFromMatrix(Matrix* matrix, int index, bool select_row)
{
    int length = 0;
    if(select_row) length = matrix->columns;
    else length = matrix->rows;

    Vector vector = InitVector(length);
    for(int k = 0; k < length; k++)
    {
        if(select_row) vector.data[k] = matrix->data[index][k];
        else vector.data[k] = matrix->data[k][index];
    }

    return vector;
}


void PrintMatrix(Matrix* matrix)
{
    for(int i = 0; i < matrix->rows; i++)
    {
        Vector vector = SelectVectorFromMatrix(matrix, i, TRUE);
        PrintVector(&vector);
    }
}