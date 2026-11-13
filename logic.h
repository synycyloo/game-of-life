#ifndef LOGIC_H
#define LOGIC_H

#include "common.h"

int CountNeighbours(const int field[HEIGHT][WIDTH], int row, int col);
int CellFate(int cell, int counter);
void NextGeneration(int current_field[HEIGHT][WIDTH], int new_field[HEIGHT][WIDTH]);
void CopyField(int src_field[HEIGHT][WIDTH], int dst_field[HEIGHT][WIDTH]);

#endif