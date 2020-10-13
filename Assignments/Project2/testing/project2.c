#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 8
#define NUM_COLS 8

#define SPACE 0
#define WALL -1
#define EXIT -2

void InitialiseRoad(int road[NUM_ROWS][NUM_COLS], char side, int pos)
{
	// build walls and spaces
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			if (i == 0 || i == NUM_ROWS - 1 || j == 0 || j == NUM_COLS - 1) {
				road[i][j] = WALL;
			} else  {
				road[i][j] = SPACE;
			}
		}
	}

	// add exit
	if (side == 'N') {
		road[0][pos] = EXIT;
	} else if (side == 'E') {
		road[pos][NUM_COLS - 1] = EXIT;
	} else if (side == 'W') {
		road[pos][0] = EXIT;
	} else if (side == 'S') {
		road[NUM_ROWS - 1][pos] = EXIT;
	}
}

void PrintRoad(int road[NUM_ROWS][NUM_COLS])
{
	int i, j;
	for (i = 0; i < NUM_ROWS; i++) {
		for (j = 0; j < NUM_COLS; j++) {
			if (road[i][j] == WALL) {
				printf("%c", '#');
			} else if (road[i][j] == SPACE) {
				printf("%c", ' ');
			} else if (road[i][j] == EXIT) {
				printf("%c", 'O');
			} else {
				printf("%c", road[i][j]);
			}
		}
		printf("\n");
	}
}

double PercentUsed(int road[NUM_ROWS][NUM_COLS])
{
	int availableSpace = 0;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			if (road[i][j] == SPACE) {
				availableSpace++;
			}
		}
	}
	int totalSpace = (NUM_ROWS-2) * (NUM_COLS - 2);
	return ((double) (totalSpace - availableSpace) / totalSpace) * 100;
}

void AddCar(int road[NUM_ROWS][NUM_COLS], int row, int col, int size)
{
	int impossible = 0;
	if (size < 0) {
		for (int i = row; i < row - size; i++) {
			if (road[i][col] >= 'A' && road[i][col] <= 'Z') {
				impossible = 1;
			}
		}
		if (impossible == 0) {
			for (int i = row; i < row - size; i++) {
				road[i][col] = 'A';
			}
		} 
	} else if (size > 0) {
		for (int j = col; j < col + size; j++) {
			if (road[row][j] >= 'A' && road[row][j] <= 'Z') {
				impossible = 1;
			}	
		}
		if (impossible == 0) {
			for (int j = col; j < col + size; j++) {
				road[row][j] = 'A';
			}
		}
	}
	
}

//void FindCar(int road[NUM_ROWS][NUM_COLS], char move, int *rowStart, int *colStart, int *rowEnd, int *colEnd)
//{
//}

//int MoveCar(int road[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1)
//{
//}


/***********************************************************/
/***********************************************************/
/******* A SIMPLE MAIN FUNCTION TO TEST YOUR PROGRESS ******/
/***********************************************************/
/***********************************************************/

/* You should add your own tests in here */
int main(void)
{
	int road[NUM_ROWS][NUM_COLS];

	// Task 1
	InitialiseRoad(road, 'E', 3);

	// Task 2
	PrintRoad(road);
	
	// Task 3
	printf("Percent used: %f\n", PercentUsed(road));

	// Task 4
	InitialiseRoad(road, 'E', 3);
	AddCar(road, 3, 1, 2);
	AddCar(road, 2, 4, -4);
	AddCar(road, 5, 3, 3);
	AddCar(road, 6, 3, 3);
	PrintRoad(road);
	printf("Percent used: %f\n", PercentUsed(road));

	return 0;
}
