#include "logic.h"

int CountNeighbours(const int field[HEIGHT][WIDTH], int row, int col) {
    int counter = 0;
    for (int d_row = -1; d_row <= 1; d_row++) {
        for (int d_col = -1; d_col <= 1; d_col++) {
            if ((d_row != 0 || d_col != 0) &&
                (field[(row + d_row + HEIGHT) % HEIGHT][(col + d_col + WIDTH) % WIDTH] == 1)) {
                counter++;
            };
        }
    }
    return counter;
}

int CellFate(int cell, int counter) {
    int result = DEAD;
    if (counter == 3 || (cell == ALIVE && counter == 2)) {
        result = ALIVE;
    }
    return result;
}

void NextGeneration(int current_field[HEIGHT][WIDTH], int new_field[HEIGHT][WIDTH]) {
    int counter;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            counter = CountNeighbours(current_field, i, j);
            new_field[i][j] = CellFate(current_field[i][j], counter);
        }
    }
}

void CopyField(int src_field[HEIGHT][WIDTH], int dst_field[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            dst_field[i][j] = src_field[i][j];
        }
    }
}