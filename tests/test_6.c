#include <stdio.h>
#include "board.h"
#include "list.h"
#include "solver.h"

void Test6()
{
    List row_data0 = InitList(0);
    AppendToList(&row_data0, 1);
    AppendToList(&row_data0, 3);
    AppendToList(&row_data0, 5);
    AppendToList(&row_data0, 2);

    List row_data1 = InitList(0);
    AppendToList(&row_data1, 8);
    AppendToList(&row_data1, 6);

    List row_data2 = InitList(0);
    AppendToList(&row_data2, 1);
    AppendToList(&row_data2, 14);

    List row_data3 = InitList(0);
    AppendToList(&row_data3, 11);
    AppendToList(&row_data3, 1);
    AppendToList(&row_data3, 3);

    List row_data4 = InitList(0);
    AppendToList(&row_data4, 6);
    AppendToList(&row_data4, 3);
    AppendToList(&row_data4, 1);

    List row_data5 = InitList(0);
    AppendToList(&row_data5, 4);
    AppendToList(&row_data5, 2);

    List row_data6 = InitList(0);
    AppendToList(&row_data6, 3);
    AppendToList(&row_data6, 1);
    AppendToList(&row_data6, 1);

    List row_data7 = InitList(0);
    AppendToList(&row_data7, 7);

    List row_data8 = InitList(0);
    AppendToList(&row_data8, 3);
    AppendToList(&row_data8, 4);
    AppendToList(&row_data8, 1);
    AppendToList(&row_data8, 1);

    List row_data9 = InitList(0);
    AppendToList(&row_data9, 1);
    AppendToList(&row_data9, 4);
    AppendToList(&row_data9, 1);

    List row_data10 = InitList(0);
    AppendToList(&row_data10, 6);
    AppendToList(&row_data10, 1);
    AppendToList(&row_data10, 1);
    AppendToList(&row_data10, 4);

    List row_data11 = InitList(0);
    AppendToList(&row_data11, 8);
    AppendToList(&row_data11, 1);
    AppendToList(&row_data11, 4);

    List row_data12 = InitList(0);
    AppendToList(&row_data12, 9);
    AppendToList(&row_data12, 2);
    AppendToList(&row_data12, 3);

    List row_data13 = InitList(0);
    AppendToList(&row_data13, 11);
    AppendToList(&row_data13, 1);
    AppendToList(&row_data13, 2);

    List row_data14 = InitList(0);
    AppendToList(&row_data14, 5);
    AppendToList(&row_data14, 4);
    AppendToList(&row_data14, 3);
    AppendToList(&row_data14, 2);

    List row_data15 = InitList(0);
    AppendToList(&row_data15, 2);
    AppendToList(&row_data15, 3);
    AppendToList(&row_data15, 3);
    AppendToList(&row_data15, 3);

    List row_data16 = InitList(0);
    AppendToList(&row_data16, 4);
    AppendToList(&row_data16, 1);
    AppendToList(&row_data16, 6);

    List row_data17 = InitList(0);
    AppendToList(&row_data17, 3);
    AppendToList(&row_data17, 1);
    AppendToList(&row_data17, 1);

    List row_data18 = InitList(0);
    AppendToList(&row_data18, 4);

    List row_data19 = InitList(0);
    AppendToList(&row_data19, 3);
    AppendToList(&row_data19, 1);

    List column_data0 = InitList(0);
    AppendToList(&column_data0, 1);
    AppendToList(&column_data0, 1);
    AppendToList(&column_data0, 6);

    List column_data1 = InitList(0);
    AppendToList(&column_data1, 3);
    AppendToList(&column_data1, 7);

    List column_data2 = InitList(0);
    AppendToList(&column_data2, 5);
    AppendToList(&column_data2, 11);

    List column_data3 = InitList(0);
    AppendToList(&column_data3, 4);
    AppendToList(&column_data3, 7);
    AppendToList(&column_data3, 4);

    List column_data4 = InitList(0);
    AppendToList(&column_data4, 15);
    AppendToList(&column_data4, 4);

    List column_data5 = InitList(0);
    AppendToList(&column_data5, 5);
    AppendToList(&column_data5, 7);
    AppendToList(&column_data5, 1);

    List column_data6 = InitList(0);
    AppendToList(&column_data6, 4);
    AppendToList(&column_data6, 1);
    AppendToList(&column_data6, 3);

    List column_data7 = InitList(0);
    AppendToList(&column_data7, 3);
    AppendToList(&column_data7, 8);
    AppendToList(&column_data7, 1);

    List column_data8 = InitList(0);
    AppendToList(&column_data8, 6);
    AppendToList(&column_data8, 2);
    AppendToList(&column_data8, 4);

    List column_data9 = InitList(0);
    AppendToList(&column_data9, 9);
    AppendToList(&column_data9, 3);

    List column_data10 = InitList(0);
    AppendToList(&column_data10, 5);
    AppendToList(&column_data10, 2);
    AppendToList(&column_data10, 3);

    List column_data11 = InitList(0);
    AppendToList(&column_data11, 4);

    List column_data12 = InitList(0);
    AppendToList(&column_data12, 1);
    AppendToList(&column_data12, 1);
    AppendToList(&column_data12, 4);

    List column_data13 = InitList(0);
    AppendToList(&column_data13, 2);
    AppendToList(&column_data13, 6);

    List column_data14 = InitList(0);
    AppendToList(&column_data14, 2);
    AppendToList(&column_data14, 1);
    AppendToList(&column_data14, 3);

    List column_data15 = InitList(0);
    AppendToList(&column_data15, 3);
    AppendToList(&column_data15, 2);
    AppendToList(&column_data15, 1);

    List column_data16 = InitList(0);
    AppendToList(&column_data16, 3);
    AppendToList(&column_data16, 2);
    AppendToList(&column_data16, 1);

    List column_data17 = InitList(0);
    AppendToList(&column_data17, 4);
    AppendToList(&column_data17, 1);
    AppendToList(&column_data17, 1);
    AppendToList(&column_data17, 3);
    AppendToList(&column_data17, 2);

    List column_data18 = InitList(0);
    AppendToList(&column_data18, 2);
    AppendToList(&column_data18, 7);

    List column_data19 = InitList(0);
    AppendToList(&column_data19, 2);
    AppendToList(&column_data19, 1);
    AppendToList(&column_data19, 6);
    DefinitionList definition_list_rows = InitDefinitionList(20);
    DefinitionList definition_list_columns = InitDefinitionList(20);
    definition_list_rows.data[0] = InitDefinition(20, row_data0);
    definition_list_rows.data[1] = InitDefinition(20, row_data1);
    definition_list_rows.data[2] = InitDefinition(20, row_data2);
    definition_list_rows.data[3] = InitDefinition(20, row_data3);
    definition_list_rows.data[4] = InitDefinition(20, row_data4);
    definition_list_rows.data[5] = InitDefinition(20, row_data5);
    definition_list_rows.data[6] = InitDefinition(20, row_data6);
    definition_list_rows.data[7] = InitDefinition(20, row_data7);
    definition_list_rows.data[8] = InitDefinition(20, row_data8);
    definition_list_rows.data[9] = InitDefinition(20, row_data9);
    definition_list_rows.data[10] = InitDefinition(20, row_data10);
    definition_list_rows.data[11] = InitDefinition(20, row_data11);
    definition_list_rows.data[12] = InitDefinition(20, row_data12);
    definition_list_rows.data[13] = InitDefinition(20, row_data13);
    definition_list_rows.data[14] = InitDefinition(20, row_data14);
    definition_list_rows.data[15] = InitDefinition(20, row_data15);
    definition_list_rows.data[16] = InitDefinition(20, row_data16);
    definition_list_rows.data[17] = InitDefinition(20, row_data17);
    definition_list_rows.data[18] = InitDefinition(20, row_data18);
    definition_list_rows.data[19] = InitDefinition(20, row_data19);
    definition_list_columns.data[0] = InitDefinition(20, column_data0);
    definition_list_columns.data[1] = InitDefinition(20, column_data1);
    definition_list_columns.data[2] = InitDefinition(20, column_data2);
    definition_list_columns.data[3] = InitDefinition(20, column_data3);
    definition_list_columns.data[4] = InitDefinition(20, column_data4);
    definition_list_columns.data[5] = InitDefinition(20, column_data5);
    definition_list_columns.data[6] = InitDefinition(20, column_data6);
    definition_list_columns.data[7] = InitDefinition(20, column_data7);
    definition_list_columns.data[8] = InitDefinition(20, column_data8);
    definition_list_columns.data[9] = InitDefinition(20, column_data9);
    definition_list_columns.data[10] = InitDefinition(20, column_data10);
    definition_list_columns.data[11] = InitDefinition(20, column_data11);
    definition_list_columns.data[12] = InitDefinition(20, column_data12);
    definition_list_columns.data[13] = InitDefinition(20, column_data13);
    definition_list_columns.data[14] = InitDefinition(20, column_data14);
    definition_list_columns.data[15] = InitDefinition(20, column_data15);
    definition_list_columns.data[16] = InitDefinition(20, column_data16);
    definition_list_columns.data[17] = InitDefinition(20, column_data17);
    definition_list_columns.data[18] = InitDefinition(20, column_data18);
    definition_list_columns.data[19] = InitDefinition(20, column_data19);
    Board board = InitBoard(definition_list_columns, definition_list_rows);
    SolveBoard(&board);
}
