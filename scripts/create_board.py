from io import StringIO
from pathlib import Path

if __name__ == "__main__":

    rows = """
    """
    columns = """
    """

    row_base_var = "row_data"
    column_base_var = "column_data"

    row_data:tuple[str, str] = (rows, row_base_var)
    column_data:tuple[str, str] = (columns, column_base_var)
    content:list[tuple[str, str]] = [row_data, column_data]

    string = StringIO()
    for data, base_var in content:
        for vector_index, vector in enumerate(filter(lambda line: line != "", data.splitlines())):
            variable = f"{base_var}{vector_index}"
            for count_index, count in enumerate(vector.split(",")):
                if count_index == 0:
                    string.write(f"\nList {variable} = InitList(0);\n")
                string.write(f"AppendToList(&{variable}, {count.strip()});\n")

    length_of_vectors = []
    for data, _ in content:
        length_of_vectors.append(len(list(filter(lambda line: line != "", data.splitlines()))))

    string.write(f"DefinitionList definition_list_rows = InitDefinitionList({length_of_vectors[0]});\n")
    string.write(f"DefinitionList definition_list_columns = InitDefinitionList({length_of_vectors[1]});\n")
    for i in range(length_of_vectors[0]):
        string.write(f"definition_list_rows.data[{i}] = InitDefinition({length_of_vectors[1]}, {row_base_var}{i});\n")
    for i in range(length_of_vectors[1]):
        string.write(f"definition_list_columns.data[{i}] = InitDefinition({length_of_vectors[0]}, {column_base_var}{i});\n")

    string.write("Board board = InitBoard(definition_list_columns, definition_list_rows);\n")
    string.write("SolveBoard(&board);\n")

    indexes = []
    for i in Path("tests").glob("test_?.h"):
        indexes.append(int(i.name.removeprefix("test_").removesuffix(".h")))
    index = max(indexes) + 1 if len(indexes) != 0 else 0

    with open(Path("tests").joinpath(f"test_{index}.h"), "w", encoding="utf-8") as file:
        file.writelines([
            f"#ifndef TEST_{index}_H\n",
            f"#define TEST_{index}_H\n",
            f"void Test{index}();\n",
            "#endif"
        ])

    function_content = [
        '#include <stdio.h>\n',
        '#include "board.h"\n',
        '#include "list.h"\n',
        '#include "solver.h"\n',
        '\n',
        f'void Test{index}()\n',
        '{',
    ]

    function_content += list(map(lambda line: f"    {line}\n" if line != "" else f"{line}\n", string.getvalue().splitlines()))
    function_content += ["}\n"]

    with open(Path("tests").joinpath(f"test_{index}.c"), "w", encoding="utf-8") as file:
        file.writelines(function_content)
