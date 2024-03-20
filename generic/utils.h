#ifndef UTILS_H
#define UTILS_H

#include "matrix.h"


/// @brief Checking if an index is for a row
/// @param matrix
/// @param index
/// @return
bool IsRow(Matrix* matrix, int index);

/// @brief Gets a row index based on the general index
/// @param matrix
/// @param index general index of the matrix
/// @return
int GetRowIndex(Matrix* matrix, int index);

/// @brief Gets a column index based on the general index
/// @param matrix
/// @param index general index of the matrix
/// @return
int GetColumnIndex(Matrix* matrix, int index);


#endif