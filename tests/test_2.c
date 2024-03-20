#include <stdio.h>
#include "board.h"
#include "list.h"
#include "solver.h"

void Test2()
{
    List row_data0 = InitList(0);
    AppendToList(&row_data0, 3);

    List row_data1 = InitList(0);
    AppendToList(&row_data1, 3);

    List row_data2 = InitList(0);
    AppendToList(&row_data2, 3);

    List row_data3 = InitList(0);
    AppendToList(&row_data3, 1);

    List row_data4 = InitList(0);
    AppendToList(&row_data4, 1);
    AppendToList(&row_data4, 2);

    List column_data0 = InitList(0);
    AppendToList(&column_data0, 3);

    List column_data1 = InitList(0);
    AppendToList(&column_data1, 3);
    AppendToList(&column_data1, 1);

    List column_data2 = InitList(0);
    AppendToList(&column_data2, 3);

    List column_data3 = InitList(0);
    AppendToList(&column_data3, 1);

    List column_data4 = InitList(0);
    AppendToList(&column_data4, 2);
    DefinitionList definition_list_rows = InitDefinitionList(5);
    DefinitionList definition_list_columns = InitDefinitionList(5);
    definition_list_rows.data[0] = InitDefinition(5, row_data0);
    definition_list_rows.data[1] = InitDefinition(5, row_data1);
    definition_list_rows.data[2] = InitDefinition(5, row_data2);
    definition_list_rows.data[3] = InitDefinition(5, row_data3);
    definition_list_rows.data[4] = InitDefinition(5, row_data4);
    definition_list_columns.data[0] = InitDefinition(5, column_data0);
    definition_list_columns.data[1] = InitDefinition(5, column_data1);
    definition_list_columns.data[2] = InitDefinition(5, column_data2);
    definition_list_columns.data[3] = InitDefinition(5, column_data3);
    definition_list_columns.data[4] = InitDefinition(5, column_data4);
    Board board = InitBoard(definition_list_columns, definition_list_rows);
    SolveBoard(&board);
}
