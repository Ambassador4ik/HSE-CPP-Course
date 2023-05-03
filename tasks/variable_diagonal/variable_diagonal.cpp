#include "variable_diagonal.h"

int** BuildDiagonalArray(size_t lines, size_t columns) {
    int** table = new int*[lines];
    for (int i = 0; i < static_cast<int>(lines); ++i) {
        table[i] = new int[columns];
    }
    int num = 0;
    for (int k = 0; k < static_cast<int>(lines + columns - 1); ++k) {
        for (int i = 0; i < static_cast<int>(lines); ++i) {
            for (int j = 0; j < static_cast<int>(columns); ++j) {
                if (i + j == k) {
                    table[i][j] = ++num - 1;
                }
            }
        }
    }
    return table;
}