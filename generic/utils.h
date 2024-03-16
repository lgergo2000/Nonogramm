#ifndef UTILS_H
#define UTILS_H

#include "matrix.h"


/// @brief Checking if an index is for a row
/// @param matrix Matrix
/// @param index int
/// @return
bool IsRow(Matrix matrix, int index);


int GetRowIndex(Matrix matrix, int index);
int GetColumnIndex(Matrix matrix, int index);


#endif