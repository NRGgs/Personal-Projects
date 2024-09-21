#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 21

// Directions for moving in the maze
const int dRow[] = { -2, 2, 0, 0 };
const int dCol[] = { 0, 0, -2, 2 };

// Maze initialization
void initializeMaze(int maze[HEIGHT][WIDTH]) {
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            maze[r][c] = 1;  // 1 means wall
        }
    }
}

// Check if position is within bounds
int isInBounds(int r, int c) {
    return (r > 0 && r < HEIGHT-1 && c > 0 && c < WIDTH-1);
}

// Check if a cell has been visited
int isVisited(int maze[HEIGHT][WIDTH], int r, int c) {
    return (maze[r][c] == 0);
}

// Randomly shuffle directions
void shuffleDirections(int directions[4][2]) {
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp[2] = { directions[i][0], directions[i][1] };
        directions[i][0] = directions[j][0];
        directions[i][1] = directions[j][1];
        directions[j][0] = temp[0];
        directions[j][1] = temp[1];
    }
}

// Recursive DFS function
void generateMaze(int maze[HEIGHT][WIDTH], int r, int c) {
    maze[r][c] = 0;  // Mark the cell as visited

    int directions[4][2] = { { -2, 0 }, { 2, 0 }, { 0, -2 }, { 0, 2 } };
    shuffleDirections(directions);

    for (int i = 0; i < 4; i++) {
        int newRow = r + directions[i][0];
        int newCol = c + directions[i][1];
        int wallRow = r + directions[i][0] / 2;
        int wallCol = c + directions[i][1] / 2;

        if (isInBounds(newRow, newCol) && !isVisited(maze, newRow, newCol)) {
            maze[wallRow][wallCol] = 0;  // Remove the wall
            generateMaze(maze, newRow, newCol);
        }
    }
}

// Set entrance and exit
void setEntranceAndExit(int maze[HEIGHT][WIDTH]) {
    // Entrance at (1, 0)
    maze[1][0] = 0;
    
    // Exit at (HEIGHT-2, WIDTH-1) for simplicity
    maze[HEIGHT-2][WIDTH-1] = 0;
}

// Print the maze
void printMaze(int maze[HEIGHT][WIDTH]) {
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            if (maze[r][c] == 1) {
                printf("#");
            } else if (r == 1 && c == 0) {
                printf("S");  // Entrance
            } else if (r == HEIGHT-2 && c == WIDTH-1) {
                printf("E");  // Exit
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));  // Seed for random number generation

    int maze[HEIGHT][WIDTH];
    initializeMaze(maze);

    // Start generating the maze from (1, 1)
    generateMaze(maze, 1, 1);

    // Set entrance and exit
    setEntranceAndExit(maze);

    // Print the generated maze
    printMaze(maze);

    return 0;
}
