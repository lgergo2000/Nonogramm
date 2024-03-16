#ifndef FILL_MATRIX_WITH_VECTOR
#define FILL_MATRIX_WITH_VECTOR

#include "matrix.h"

/// @brief Fill matrix with the vector if possible
/// @param matrix Matrix*
/// @param vector Vector
/// @param definition_index int
/// @return `-1`: not possible to fill; `1`: possible to fill
int FillMatrixWithVectorIfPossible(Matrix* matrix, Vector vector, int definition_index);

#endif