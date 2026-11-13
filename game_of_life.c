#include "common.h"
#include "input.h"
#include "logic.h"
#include "output.h"

void GameLoop(int current_field[HEIGHT][WIDTH]);

int main(void) {
    int current_field[HEIGHT][WIDTH] = {0};
    int status = 0;

    if (!ReadField(current_field) || !ReopenTty()) {
        PrintError();
        status = 1;
    } else {
        InitScreen();
        GameLoop(current_field);
        CloseScreen();
    }
    return status;
}

void GameLoop(int current_field[HEIGHT][WIDTH]) {
    int delay = DELAY_START;
    int is_running = 1;
    int next_field[HEIGHT][WIDTH] = {0};

    while (is_running) {
        DrawField(current_field, delay);
        HandleKey(PollKey(delay), &delay, &is_running);
        NextGeneration(current_field, next_field);
        CopyField(next_field, current_field);
    }
}
