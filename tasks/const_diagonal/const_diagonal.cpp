#include "const_diagonal.h"

void BuildDiagonalArray(TableType table) {
    int num = 0;
    for (int k = 0; k < LINES + COLUMNS - 1; ++k) {
        for (int i = 0; i < LINES; ++i) {
            for (int j = 0; j < COLUMNS; ++j) {
                if (i + j == k) {
                    table[i][j] = ++num - 1;
                }
            }
        }
    }
}