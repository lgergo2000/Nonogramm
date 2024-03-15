#include <stdio.h>
#include "list.h"

void Printint(int* data)
{
    printf("%d, ", *data);
}

IMPLEMENT_GENERIC_LIST_FUNCTIONS(List, int)
