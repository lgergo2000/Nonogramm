#include "utils.h"

bool IsRow(Matrix* matrix, int index)
{
    if(index % 2 == 0 && (int)(index/2) < matrix->rows) return TRUE;
    return FALSE;
}

int GetRowIndex(Matrix* matrix, int index)
{
    if(IsRow(matrix, index)) return (int)(index/2);
    else return -1;
}
int GetColumnIndex(Matrix* matrix, int index)
{
    if(!IsRow(matrix, index))
    {
        if(((float)(index-1)/2 + 1) <= (float)matrix->rows)
        {
            return (int)((index-1)/2);
        }
        else
        {
            return index - matrix->rows;
        }

    }
    else return -1;
}