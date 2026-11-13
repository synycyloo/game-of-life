#ifndef OUTPUT_H
#define OUTPUT_H

#include "common.h"

void InitScreen(void);

void DrawField(int field[HEIGHT][WIDTH], int delay);

void DrawCells(int field[HEIGHT][WIDTH]);

void DrawHint(int delay);

void CloseScreen(void);

void PrintError(void);

#endif
