# Treasure-hunt-game-in-C
Mini Maze Treasure Hunt is a terminal-based maze exploration game written in C. The maze is generated dynamically using a recursive backtracking algorithm, ensuring that each run creates a unique layout. The player navigates through the maze to collect hidden treasures while avoiding walls. 

The game includes interactive movement controls, randomly placed treasures, a teleportation portal feature, and a timer that records how long it takes the player to collect all treasures.

The project demonstrates concepts such as:
Recursive algorithms
Maze generation
2D array manipulation
Randomization
Basic game mechanics
User input handling

It is designed as a simple console game and can also serve as a beginner project for learning C programming and algorithmic problem solving.




**Mini Maze Treasure Hunt (C)**

A simple console-based maze game written in C where the player explores a randomly generated maze and collects hidden treasures.
Each run generates a new maze, making the game different every time.

**Features**
Random maze generation using recursive backtracking
5 hidden treasures placed randomly
Player movement using WASD controls
Teleport portal to jump to a random location
Treasure counter
Game timer to track completion time
Simple terminal-based interface

**Game Symbols**
Symbol	Meaning
#	Wall
.	Walkable path
T	Treasure
P	Player
Controls
Key	Action
W	Move Up
A	Move Left
S	Move Down
D	Move Right
P	Teleport to random location

**How the Game Works**
The maze is generated using a depth-first recursive maze generation algorithm.
The player starts at position (1,1).
5 treasures are placed randomly on valid paths.
The player navigates through the maze using WASD keys.
If the player steps on a treasure, it gets collected.
The game ends when all treasures are collected.
The total time taken to finish the game is displayed.

Use " _gcc treasure_hunt.c -o treasure_ " to compile using gcc
followed by " _./treasure_ "


**Possible Improvements**
Future versions could include:
Larger maze sizes
Difficulty levels
Multiple levels
Save/load functionality
Scoreboards
Color output
Better graphics using libraries like ncurses
