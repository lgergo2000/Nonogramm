#ifndef FILL_MATRIX_WITH_VECTOR
#define FILL_MATRIX_WITH_VECTOR

#include "matrix.h"

/// @brief Fill matrix with the vector if possible
/// @param matrix
/// @param vector vector to fill to the matrix
/// @param definition_index general index of the vector
/// @param tmp vector that used for vector selection from the matrix (used for RAM usage optimization)
/// @return `-1`: not possible to fill; `1`: possible to fill
int FillMatrixWithVectorIfPossible(Matrix* matrix, Vector* vector, int definition_index, Vector* tmp);

#endif