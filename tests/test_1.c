#include <stdio.h>
#include "board.h"
#include "list.h"
#include "solver.h"

void Test1()
{
    List row_data0 = InitList(0);
    AppendToList(&row_data0, 2);

    List row_data1 = InitList(0);
    AppendToList(&row_data1, 1);
    AppendToList(&row_data1, 1);

    List row_data2 = InitList(0);
    AppendToList(&row_data2, 2);
    AppendToList(&row_data2, 1);
    AppendToList(&row_data2, 3);
    AppendToList(&row_data2, 1);

    List row_data3 = InitList(0);
    AppendToList(&row_data3, 2);
    AppendToList(&row_data3, 3);
    AppendToList(&row_data3, 2);
    AppendToList(&row_data3, 2);

    List row_data4 = InitList(0);
    AppendToList(&row_data4, 2);
    AppendToList(&row_data4, 3);
    AppendToList(&row_data4, 2);

    List row_data5 = InitList(0);
    AppendToList(&row_data5, 1);
    AppendToList(&row_data5, 2);
    AppendToList(&row_data5, 3);
    AppendToList(&row_data5, 2);

    List row_data6 = InitList(0);
    AppendToList(&row_data6, 2);
    AppendToList(&row_data6, 10);

    List row_data7 = InitList(0);
    AppendToList(&row_data7, 14);

    List row_data8 = InitList(0);
    AppendToList(&row_data8, 7);
    AppendToList(&row_data8, 6);

    List row_data9 = InitList(0);
    AppendToList(&row_data9, 3);
    AppendToList(&row_data9, 2);

    List row_data10 = InitList(0);
    AppendToList(&row_data10, 2);
    AppendToList(&row_data10, 2);
    AppendToList(&row_data10, 2);
    AppendToList(&row_data10, 1);

    List row_data11 = InitList(0);
    AppendToList(&row_data11, 4);
    AppendToList(&row_data11, 1);

    List row_data12 = InitList(0);
    AppendToList(&row_data12, 2);
    AppendToList(&row_data12, 3);
    AppendToList(&row_data12, 6);

    List row_data13 = InitList(0);
    AppendToList(&row_data13, 2);
    AppendToList(&row_data13, 2);
    AppendToList(&row_data13, 1);

    List row_data14 = InitList(0);
    AppendToList(&row_data14, 6);

    List column_data0 = InitList(0);
    AppendToList(&column_data0, 2);
    AppendToList(&column_data0, 1);
    AppendToList(&column_data0, 2);

    List column_data1 = InitList(0);
    AppendToList(&column_data1, 3);
    AppendToList(&column_data1, 3);
    AppendToList(&column_data1, 2);

    List column_data2 = InitList(0);
    AppendToList(&column_data2, 1);
    AppendToList(&column_data2, 7);
    AppendToList(&column_data2, 1);

    List column_data3 = InitList(0);
    AppendToList(&column_data3, 1);
    AppendToList(&column_data3, 1);
    AppendToList(&column_data3, 4);
    AppendToList(&column_data3, 1);

    List column_data4 = InitList(0);
    AppendToList(&column_data4, 3);
    AppendToList(&column_data4, 1);

    List column_data5 = InitList(0);
    AppendToList(&column_data5, 8);
    AppendToList(&column_data5, 1);
    AppendToList(&column_data5, 1);

    List column_data6 = InitList(0);
    AppendToList(&column_data6, 7);
    AppendToList(&column_data6, 1);
    AppendToList(&column_data6, 1);
    AppendToList(&column_data6, 1);

    List column_data7 = InitList(0);
    AppendToList(&column_data7, 3);
    AppendToList(&column_data7, 2);
    AppendToList(&column_data7, 1);
    AppendToList(&column_data7, 1);
    AppendToList(&column_data7, 1);

    List column_data8 = InitList(0);
    AppendToList(&column_data8, 3);
    AppendToList(&column_data8, 1);

    List column_data9 = InitList(0);
    AppendToList(&column_data9, 1);
    AppendToList(&column_data9, 9);

    List column_data10 = InitList(0);
    AppendToList(&column_data10, 1);
    AppendToList(&column_data10, 1);
    AppendToList(&column_data10, 9);

    List column_data11 = InitList(0);
    AppendToList(&column_data11, 3);
    AppendToList(&column_data11, 2);

    List column_data12 = InitList(0);
    AppendToList(&column_data12, 3);
    AppendToList(&column_data12, 1);

    List column_data13 = InitList(0);
    AppendToList(&column_data13, 6);
    AppendToList(&column_data13, 1);

    List column_data14 = InitList(0);
    AppendToList(&column_data14, 7);
    AppendToList(&column_data14, 4);
    DefinitionList definition_list_rows = InitDefinitionList(15);
    DefinitionList definition_list_columns = InitDefinitionList(15);
    definition_list_rows.data[0] = InitDefinition(15, row_data0);
    definition_list_rows.data[1] = InitDefinition(15, row_data1);
    definition_list_rows.data[2] = InitDefinition(15, row_data2);
    definition_list_rows.data[3] = InitDefinition(15, row_data3);
    definition_list_rows.data[4] = InitDefinition(15, row_data4);
    definition_list_rows.data[5] = InitDefinition(15, row_data5);
    definition_list_rows.data[6] = InitDefinition(15, row_data6);
    definition_list_rows.data[7] = InitDefinition(15, row_data7);
    definition_list_rows.data[8] = InitDefinition(15, row_data8);
    definition_list_rows.data[9] = InitDefinition(15, row_data9);
    definition_list_rows.data[10] = InitDefinition(15, row_data10);
    definition_list_rows.data[11] = InitDefinition(15, row_data11);
    definition_list_rows.data[12] = InitDefinition(15, row_data12);
    definition_list_rows.data[13] = InitDefinition(15, row_data13);
    definition_list_rows.data[14] = InitDefinition(15, row_data14);
    definition_list_columns.data[0] = InitDefinition(15, column_data0);
    definition_list_columns.data[1] = InitDefinition(15, column_data1);
    definition_list_columns.data[2] = InitDefinition(15, column_data2);
    definition_list_columns.data[3] = InitDefinition(15, column_data3);
    definition_list_columns.data[4] = InitDefinition(15, column_data4);
    definition_list_columns.data[5] = InitDefinition(15, column_data5);
    definition_list_columns.data[6] = InitDefinition(15, column_data6);
    definition_list_columns.data[7] = InitDefinition(15, column_data7);
    definition_list_columns.data[8] = InitDefinition(15, column_data8);
    definition_list_columns.data[9] = InitDefinition(15, column_data9);
    definition_list_columns.data[10] = InitDefinition(15, column_data10);
    definition_list_columns.data[11] = InitDefinition(15, column_data11);
    definition_list_columns.data[12] = InitDefinition(15, column_data12);
    definition_list_columns.data[13] = InitDefinition(15, column_data13);
    definition_list_columns.data[14] = InitDefinition(15, column_data14);
    Board board = InitBoard(definition_list_columns, definition_list_rows);
    SolveBoard(&board);
}
