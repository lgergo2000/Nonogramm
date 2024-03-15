#ifndef DEFINITION_H
#define DEFINITION_H

#include "list.h"
#include "vector.h"


/// @brief
/// @param vector_length int
/// @param definition_list List
/// @param possible_vectors VectorList
/// @param index int
typedef struct
{
    int vector_length;
    List definition_list;
    VectorList possible_vectors;
    int index;
} Definition;

Definition InitDefinition(int vector_length, List definition_list);

#endif