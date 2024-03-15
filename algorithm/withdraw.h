#ifndef WITHDRAW_H
#define WITHDRAW_H

#include "matrix.h"

/// @brief Withdraw the row/column that was set at definition_index
/// @param matrix Matrix*
/// @param definition_index int: index of the definitions in row , col., row, col., ...  order
void WithdrawDefinition(Matrix* matrix, int definition_index);

#endif