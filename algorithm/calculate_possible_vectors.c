#include <stdio.h>
#include "generic_list.h"
#include "calculate_possible_vectors.h"
#include "filter.h"

/// @brief List of lists, contains the possible combination
/// @param combination List*: list of the possible combinations
/// @param count int: number of the possible combinations
typedef struct
{
    List* combinations;
    int count;
} Combination;


/// @brief Core function of the recursion:
/// if no more item to choose, then stores the result to the result, else
/// get the previous solution (see bellow) and appends each possible remaining item
/// to the solution and calls the function back
/// @param choices List: item to choose from, e.g.: [0,1,2,3,4,5]
/// @param previous List: the choosen item from the previous recursions e.g.: [0,3]
/// @param count_to_choose int: remaining item count to choose
/// @param results: Combination*
void CalculateCombinationCore(List choices, List previous, int count_to_choose, Combination* results)
{
    if(count_to_choose==0)//store the previous the the results
    {
        results->combinations = realloc(results->combinations, (results->count + 1) * sizeof(List));
        if(results->combinations == NULL) return;

        results->count++;
        results->combinations[results->count - 1] = InitList(previous.length);
        for(int k = 0; k < previous.length; k++)
        {
            results->combinations[results->count - 1].data[k] = previous.data[k];
        }
        return;
    }
    for(int i = 0; i < choices.length; i++)
    {
        previous.data[previous.length - count_to_choose] = choices.data[i];
        CalculateCombinationCore(ListSliceByLeftIndex(choices, i + 1), previous, count_to_choose - 1, results);
    }
}


/// @brief Main combination calculation function (CalculateCombinationCore's wrapper),
/// that initialize the recursion
/// @param choices List: item to choose from, e.g.: [0,1,2,3,4,5]
/// @param count_to_choose int: number of element to choose from the `choices`
/// @return
Combination CalculateCombination(List choices, int count_to_choose)
{
    Combination results = {NULL, 0};
    List previous = InitList(count_to_choose);
    CalculateCombinationCore(choices, previous, count_to_choose, &results);

    return results;
}


/// @brief Creates a vector from the definition
/// @param field_indexes List: start indexes of the reduced vector field:
/// shrinks the definition to one length fields and contains the empty fields as well, e.g.: [0,1,2,3,4,5]
/// @param indexes_to_fill List: indexes of the fields that has to be filled
/// @param definition_list List: contains the lengths of the filled fields
/// @param length_of_vector int: length of the vector
/// @return
Vector FillVectorFromList(List field_indexes, List indexes_to_fill, List definition_list, int length_of_vector)
{
    int choices_index = 0;
    int result_index = 0;
    Vector result = InitVector(length_of_vector);
    for(int i = 0; i < length_of_vector; i++) result.data[i] = EMPTY;

    for(int i = 0; i < field_indexes.length; i++)
    {
        if(field_indexes.data[i] == indexes_to_fill.data[choices_index])
        {
            for(int j = 0; j < definition_list.data[choices_index]; j++)
            {
                result.data[result_index++] = FILLED;
            }
            result_index++;
            choices_index++;
        }
        else result_index++;
    }

    return result;
}


void SetPossibleVector(Definition* definition, int length_of_vector)
{
    int sum_of_colored_blocks = 0;
    for(int i = 0; i < definition->definition_list.length; i++)
    {
        sum_of_colored_blocks += definition->definition_list.data[i];
    }
    sum_of_colored_blocks += (definition->definition_list.length - 1);
    int free_blocks = length_of_vector - sum_of_colored_blocks;
    int number_of_blocks = free_blocks + definition->definition_list.length;

    List field_indexes = InitList(number_of_blocks);
    for(int i = 0; i < number_of_blocks; i++)
    {
        field_indexes.data[i] = i;
    }

    Combination combinations = CalculateCombination(field_indexes, definition->definition_list.length);

    definition->possible_vectors = InitVectorList(combinations.count);

    for(int j = 0; j < combinations.count; j++)
    {
        definition->possible_vectors.data[j] = FillVectorFromList(field_indexes, combinations.combinations[j], definition->definition_list, length_of_vector);
    }

}
