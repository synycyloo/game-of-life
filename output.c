#include "output.h"

#include <ncurses.h>
#include <stdio.h>

void InitScreen(void) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
}

void DrawField(int field[HEIGHT][WIDTH], int delay) {
    erase();
    DrawCells(field);
    DrawHint(delay);
    refresh();
}

void DrawCells(int field[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            mvaddch(i + 1, j + 1, field[i][j] == ALIVE ? '*' : '.');
        }
    }
}

void DrawHint(int delay) { mvprintw(HEIGHT + 1, 0, "delay: %d ms ", delay); }

void CloseScreen(void) { endwin(); }

void PrintError(void) { printf("n/a\n"); }
