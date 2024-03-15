#include "withdraw.h"

void WithdrawDefinition(Matrix* matrix, int definition_index)
{
    if(definition_index%2 == 0 && (int)(definition_index/2) < matrix->rows) // rows
    {
        for(int i = (int)(definition_index/2); i < matrix->columns; i++)
        {
            matrix->data[(int)(definition_index/2)][i] = UNKNOWN;
        }
    }
    else // cols
    {
        if((int)((definition_index+1)/2) < matrix->rows)
        {
            for(int i = (int)((definition_index+1)/2); i < matrix->rows; i++)
            {
                matrix->data[i][(int)((definition_index+1)/2)-1] = UNKNOWN;
            }
        }
    }
}