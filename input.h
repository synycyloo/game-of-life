#ifndef INPUT_H
#define INPUT_H

#include "common.h"

int ReadField(int field[HEIGHT][WIDTH]);

int ReadCell(int *cell);

int ReopenTty(void);

int PollKey(int delay);

void HandleKey(int key, int *delay, int *is_running);

#endif
