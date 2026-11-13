# Game of Life

A terminal-based implementation of Conway's Game of Life written in C using the `ncurses` library.

## Overview

The Game of Life is a cellular automaton in which cells evolve from generation to generation according to a set of rules.

The simulation runs on a fixed-size board of 80 × 25 cells with periodic boundary conditions: cells at the edges of the board are considered neighbors of cells on the opposite edges.

Each cell can be either alive or dead. Its state in the next generation is determined by the states of its eight neighboring cells:

- A live cell with fewer than two live neighbors dies (underpopulation).
- A live cell with two or three live neighbors survives.
- A live cell with more than three live neighbors dies (overpopulation).
- A dead cell with exactly three live neighbors becomes alive (reproduction).

## Features

- Cellular automaton simulation based on Conway's Game of Life rules.
- ASCII graphics rendered in the terminal using `ncurses`.
- Interactive simulation with adjustable speed.
- Periodic boundary conditions.
- Initial board configuration loaded from standard input.
- Multiple predefined initial configurations for quick startup.

## Controls

| Key | Action |
|---|---|
| `A` | Increase simulation speed |
| `Z` | Decrease simulation speed |
| `Space` | Stop the simulation |

## Requirements

- GCC compiler
- Make
- `ncurses` library

## Build

Clone the repository:

```bash
git clone https://github.com/synycyloo/game-of-life.git
cd game-of-life
```

Compile the project:

```bash
make
```

## Run

Start the simulation by redirecting an initial configuration file to standard input:

```bash
./game_of_life < maps/glider.txt
```

Replace `glider.txt` with any other available initial configuration.

## Project Structure

```text
game-of-life/
├── src/
│   ├── game_of_life.c
│   ├── logic.c
│   ├── logic.h
│   ├── input.c
│   ├── input.h
│   ├── output.c
│   └── output.h
│   └── Makefile
├── maps/
│   ├── pattern1.txt
│   ├── pattern2.txt
│   ├── pattern3.txt
│   ├── pattern4.txt
│   └── pattern5.txt
└── README.md
```

## Technologies

- C
- ncurses
- GCC
- Make
