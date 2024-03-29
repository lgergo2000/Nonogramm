#ifndef CALCULATE_POSSIBLE_VECTORS_H
#define CALCULATE_POSSIBLE_VECTORS_H
#include "definition.h"
#include "vector.h"


/// @brief Calculates the possible vectors for a definition and stores them in the definition struct
/// @param definition definition pointer that has the definition of the vector
/// @param length_of_vector length of the vector to create
void SetPossibleVector(Definition* definition, int length_of_vector);

#endif