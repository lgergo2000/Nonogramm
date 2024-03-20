#include <stdio.h>
#include "board.h"
#include "list.h"
#include "solver.h"

void Test4()
{
    List row_data0 = InitList(0);
    AppendToList(&row_data0, 4);
    AppendToList(&row_data0, 3);

    List row_data1 = InitList(0);
    AppendToList(&row_data1, 3);
    AppendToList(&row_data1, 3);

    List row_data2 = InitList(0);
    AppendToList(&row_data2, 5);
    AppendToList(&row_data2, 3);

    List row_data3 = InitList(0);
    AppendToList(&row_data3, 1);
    AppendToList(&row_data3, 1);

    List row_data4 = InitList(0);
    AppendToList(&row_data4, 2);

    List row_data5 = InitList(0);
    AppendToList(&row_data5, 2);

    List row_data6 = InitList(0);
    AppendToList(&row_data6, 3);

    List row_data7 = InitList(0);
    AppendToList(&row_data7, 4);

    List row_data8 = InitList(0);
    AppendToList(&row_data8, 4);
    AppendToList(&row_data8, 5);

    List row_data9 = InitList(0);
    AppendToList(&row_data9, 2);
    AppendToList(&row_data9, 5);

    List column_data0 = InitList(0);
    AppendToList(&column_data0, 1);
    AppendToList(&column_data0, 2);

    List column_data1 = InitList(0);
    AppendToList(&column_data1, 1);
    AppendToList(&column_data1, 1);
    AppendToList(&column_data1, 2);

    List column_data2 = InitList(0);
    AppendToList(&column_data2, 3);
    AppendToList(&column_data2, 1);
    AppendToList(&column_data2, 1);
    AppendToList(&column_data2, 1);

    List column_data3 = InitList(0);
    AppendToList(&column_data3, 3);
    AppendToList(&column_data3, 3);
    AppendToList(&column_data3, 1);

    List column_data4 = InitList(0);
    AppendToList(&column_data4, 4);
    AppendToList(&column_data4, 3);

    List column_data5 = InitList(0);
    AppendToList(&column_data5, 3);

    List column_data6 = InitList(0);
    AppendToList(&column_data6, 3);

    List column_data7 = InitList(0);
    AppendToList(&column_data7, 4);
    AppendToList(&column_data7, 3);

    List column_data8 = InitList(0);
    AppendToList(&column_data8, 3);
    AppendToList(&column_data8, 2);

    List column_data9 = InitList(0);
    AppendToList(&column_data9, 3);
    AppendToList(&column_data9, 2);
    DefinitionList definition_list_rows = InitDefinitionList(10);
    DefinitionList definition_list_columns = InitDefinitionList(10);
    definition_list_rows.data[0] = InitDefinition(10, row_data0);
    definition_list_rows.data[1] = InitDefinition(10, row_data1);
    definition_list_rows.data[2] = InitDefinition(10, row_data2);
    definition_list_rows.data[3] = InitDefinition(10, row_data3);
    definition_list_rows.data[4] = InitDefinition(10, row_data4);
    definition_list_rows.data[5] = InitDefinition(10, row_data5);
    definition_list_rows.data[6] = InitDefinition(10, row_data6);
    definition_list_rows.data[7] = InitDefinition(10, row_data7);
    definition_list_rows.data[8] = InitDefinition(10, row_data8);
    definition_list_rows.data[9] = InitDefinition(10, row_data9);
    definition_list_columns.data[0] = InitDefinition(10, column_data0);
    definition_list_columns.data[1] = InitDefinition(10, column_data1);
    definition_list_columns.data[2] = InitDefinition(10, column_data2);
    definition_list_columns.data[3] = InitDefinition(10, column_data3);
    definition_list_columns.data[4] = InitDefinition(10, column_data4);
    definition_list_columns.data[5] = InitDefinition(10, column_data5);
    definition_list_columns.data[6] = InitDefinition(10, column_data6);
    definition_list_columns.data[7] = InitDefinition(10, column_data7);
    definition_list_columns.data[8] = InitDefinition(10, column_data8);
    definition_list_columns.data[9] = InitDefinition(10, column_data9);
    Board board = InitBoard(definition_list_columns, definition_list_rows);
    SolveBoard(&board);
}
