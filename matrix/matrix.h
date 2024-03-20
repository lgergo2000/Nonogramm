#ifndef MATRIX_H
#define MATRIX_H
#include "state.h"
#include "vector.h"


/// @brief Board representation
/// @param data int**
/// @param rows int
/// @param columns int
typedef struct
{
    State **data;
    int rows;
    int columns;
} Matrix;


/// @brief Initialize the board with given size
/// @param rows int
/// @param columns int
/// @return
Matrix MatrixInit(int rows, int columns);


/// @brief Free the arrays
/// @param matrix
void MatrixFree(Matrix* matrix);


/// @brief Selects a vector from the matrix at the index,
/// if select_row is TRUE selects a row, else selects a column
/// @param matrix
/// @param index
/// @param select_row
/// @return
void SelectVectorFromMatrix(Matrix* matrix, int index, bool select_row, Vector* result_vector);

/// @brief Prints the matrix
/// @param matrix
void PrintMatrix(Matrix matrix);

#endif