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

/// @brief Print defintion block
/// @param definition
void PrintDefinition(Definition definition);

/// @brief Initialize the definition block with given length
/// @param vector_length
/// @param definition_list
/// @return
Definition InitDefinition(int vector_length, List definition_list);

DEFINE_GENERIC_LIST_FUNCTIONS_HEADER(DefinitionList, Definition)

#endif