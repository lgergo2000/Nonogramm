#include "definition.h"
#include "calculate_possible_vectors.h"

Definition InitDefinition(int vector_length, List definition_list)
{
    Definition definition;
    definition.index = -1;
    definition.vector_length = vector_length;
    definition.definition_list = definition_list;
    SetPossibleVector(&definition, vector_length);

    return definition;
}

void PrintDefinition(Definition definition)
{
    PrintList(definition.definition_list);
}

IMPLEMENT_GENERIC_LIST_FUNCTIONS(DefinitionList, Definition)