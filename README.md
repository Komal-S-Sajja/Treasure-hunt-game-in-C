# Mini Maze Treasure Hunt (C)

A simple console-based maze game written in **C** where the player explores a randomly generated maze and collects hidden treasures.

Each run generates a **new maze**, making the game different every time.

---

## Features

- Random maze generation using **recursive backtracking**
- **5 hidden treasures** placed randomly
- **Player movement using WASD controls**
- **Teleport portal** to jump to a random location
- **Treasure counter**
- **Game timer** to track completion time
- Simple **terminal-based interface**

---

## Game Symbols

| Symbol | Meaning |
|------|------|
| `#` | Wall |
| `.` | Walkable path |
| `T` | Treasure |
| `P` | Player |

---

## Controls

| Key | Action |
|----|----|
| W | Move Up |
| A | Move Left |
| S | Move Down |
| D | Move Right |
| P | Teleport to random location |

---

## How the Game Works

1. The maze is generated using a **recursive maze generation algorithm**.
2. The player starts at position **(1,1)**.
3. **5 treasures** are placed randomly on valid paths.
4. The player navigates through the maze using **WASD keys**.
5. If the player steps on a treasure, it gets collected.
6. The game ends when **all treasures are collected**.
7. The total time taken to finish the game is displayed.

---

## How to Compile and Run

### Using GCC (Linux / WSL / Ubuntu)

### Compile the program: " _gcc treasure_hunt.c -o treasure_ "
---

## Possible Improvements

Future versions could include:

- Larger maze sizes
- Difficulty levels
- Multiple levels
- Scoreboards
- Save/load functionality
- Better graphics using libraries like **ncurses**

---
