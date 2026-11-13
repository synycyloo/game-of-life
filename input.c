#include "input.h"

#include <ncurses.h>
#include <stdio.h>

int ReadField(int field[HEIGHT][WIDTH]) {
    int is_ok = 1;
    for (int i = 0; i < HEIGHT && is_ok; i++) {
        for (int j = 0; j < WIDTH && is_ok; j++) {
            is_ok = ReadCell(&field[i][j]);
        }
    }
    return is_ok;
}

int ReadCell(int *cell) {
    int is_ok = 1;
    int symbol = getchar();
    while (symbol == '\n' || symbol == '\r') {
        symbol = getchar();
    }
    if (symbol == '*') {
        *cell = ALIVE;
    } else if (symbol == '.' || symbol == ' ') {
        *cell = DEAD;
    } else {
        is_ok = 0;
    }
    return is_ok;
}

int ReopenTty(void) {
    int is_ok = 0;
    if (freopen("/dev/tty", "r", stdin) != NULL) {
        is_ok = 1;
    }
    return is_ok;
}

int PollKey(int delay) {
    timeout(delay);
    return getch();
}

void HandleKey(int key, int *delay, int *is_running) {
    if (key == 'a' || key == 'A') {
        *delay -= DELAY_STEP;
        if (*delay < DELAY_MIN) {
            *delay = DELAY_MIN;
        }
    } else if (key == 'z' || key == 'Z') {
        *delay += DELAY_STEP;
        if (*delay > DELAY_MAX) {
            *delay = DELAY_MAX;
        }
    } else if (key == ' ') {
        *is_running = 0;
    }
}
