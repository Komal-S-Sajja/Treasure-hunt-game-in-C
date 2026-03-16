#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 11
#define WALL 1
#define PATH 0
#define TREASURE 2
#define PLAYER 3

int dx[] = {0, 0, -2, 2};
int dy[] = {-2, 2, 0, 0};

int inBounds(int x, int y)
{
    return x > 0 && x < SIZE - 1 && y > 0 && y < SIZE - 1;
}

void generateMaze(int maze[SIZE][SIZE], int x, int y)
{
    maze[y][x] = PATH;

    int dirs[] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++)
    {
        int r = rand() % 4;
        int temp = dirs[i];
        dirs[i] = dirs[r];
        dirs[r] = temp;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[dirs[i]];
        int ny = y + dy[dirs[i]];

        if (inBounds(nx, ny) && maze[ny][nx] == WALL)
        {
            maze[y + dy[dirs[i]] / 2][x + dx[dirs[i]] / 2] = PATH;
            generateMaze(maze, nx, ny);
        }
    }
}

void displayMaze(int maze[SIZE][SIZE])
{
    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {
            switch (maze[y][x])
            {
            case WALL:
                printf("# ");
                break;
            case PATH:
                printf(". ");
                break;
            case TREASURE:
                printf("T ");
                break;
            case PLAYER:
                printf("P ");
                break;
            }
        }
        printf("\n");
    }
}

int main()
{
    int maze[SIZE][SIZE];
    int playerX = 1, playerY = 1;
    int treasureX, treasureY;
    int collected[100]; // array to store collected treasure status
    int treasureCount = 0;
    char move;

    srand(time(NULL));
    time_t startTime = time(NULL); // Start timer

    // Initialize maze
    for (int y = 0; y < SIZE; y++)
        for (int x = 0; x < SIZE; x++)
            maze[y][x] = WALL;

    generateMaze(maze, 1, 1);

    // Place multiple treasures
    for (int i = 0; i < 5; i++)
    {
        do
        {
            treasureX = rand() % SIZE;
            treasureY = rand() % SIZE;
        } while (maze[treasureY][treasureX] != PATH);
        maze[treasureY][treasureX] = TREASURE;
    }

    maze[playerY][playerX] = PLAYER;

    while (1)
    {
        printf("\n--- Mini Maze Treasure Hunt ---\n");
        displayMaze(maze);
        printf("Collected: %d treasures\n", treasureCount);
        printf("Move (WASD or P=Portal): ");
        scanf(" %c", &move);

        int newX = playerX, newY = playerY;

        if (move == 'p' || move == 'P')
        {
            // Portal: teleport to a random path
            do
            {
                newX = rand() % SIZE;
                newY = rand() % SIZE;
            } while (maze[newY][newX] != PATH);
            printf("✨ Portal activated!\n");
        }
        else
        {
            switch (move)
            {
            case 'w':
            case 'W':
                newY--;
                break;
            case 's':
            case 'S':
                newY++;
                break;
            case 'a':
            case 'A':
                newX--;
                break;
            case 'd':
            case 'D':
                newX++;
                break;
            default:
                printf("Invalid input.\n");
                continue;
            }
        }

        if (maze[newY][newX] == WALL)
        {
            printf("You hit a wall!\n");
            continue;
        }

        if (maze[newY][newX] == TREASURE)
        {
            printf("🎉 You found a treasure at (%d, %d)!\n", newX, newY);
            collected[treasureCount++] = 1;
        }

        // Move player
        maze[playerY][playerX] = PATH;
        playerX = newX;
        playerY = newY;
        maze[playerY][playerX] = PLAYER;

        // Optional: End game if all 5 treasures are collected
        if (treasureCount >= 5)
        {
            time_t endTime = time(NULL);
            printf("\n🏆 All treasures collected! Total Time: %ld seconds\n", endTime - startTime);
            break;
        }
    }

    return 0;
}