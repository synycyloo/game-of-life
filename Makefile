CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDLIBS = -lncurses
BUILD = ../build
TARGET = $(BUILD)/game_of_life
SRCS = game_of_life.c logic.c input.c output.c

.PHONY: all clean rebuild

all: $(TARGET)

$(TARGET): $(SRCS)
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDLIBS)

clean:
	rm -rf $(BUILD)

rebuild: clean all