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
			} else {
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
	} else {
		road[NUM_ROWS - 1][pos] = EXIT;
	}
}

void PrintRoad(int road[NUM_ROWS][NUM_COLS])
{
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
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
	int occupied = 0;
	for (int i = 1; i < NUM_ROWS - 1; i++) {
		for (int j = 1; j < NUM_COLS - 1; j++) {
			if (road[i][j] != SPACE) {
				occupied++;
			}
		}
	}
	int totalSpace = (NUM_ROWS - 2) * (NUM_COLS - 2);
	return ((double) occupied / totalSpace) * 100;
}

void AddCar(int road[NUM_ROWS][NUM_COLS], int row, int col, int size)
{
	// find the highest character
	char highestLetter = 'A' - 1;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			if (road[i][j] >= 'A' && road[i][j] <= 'Z' && road[i][j] > highestLetter) {
				highestLetter = road[i][j];
			} 
		}
	}

	// check if horizontal or vertical placement
	int impossible = 0;
	if (size < 0) {
		// check for space
		for (int i = row; i < row - size; i++) {
			if (road[i][col] != SPACE) {
				impossible = 1;
			}
		}

		// if possible place car
		if (impossible == 0) {
			for (int i = row; i < row - size; i++) {
				road[i][col] = highestLetter + 1;
			}
		} 
	} else if (size > 0) {
		// check for space
		for (int j = col; j < col + size; j++) {
			if (road[row][j] != SPACE) {
				impossible = 1;
			}	
		}

		// if possible place car
		if (impossible == 0) {
			for (int j = col; j < col + size; j++) {
				road[row][j] = highestLetter + 1;
			}
		}
	}
	
}

void FindCar(int road[NUM_ROWS][NUM_COLS], char move, int *rowStart, int *colStart, int *rowEnd, int *colEnd)
{
	// find starting position
	int startFound = 0;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			if (road[i][j] == move && startFound == 0) {
				*rowStart = i;
				*colStart = j;
				startFound = 1;
				break;
			}
		}
		if (startFound == 1) {
			break;
		}
	}

	// find end position first by checking right or down
	int i = 1; int j = 1;
	while (road[*rowStart+i][*colStart] == move)
	{
		i++;
	}
	while (road[*rowStart][*colStart+j] == move)
	{
		j++;
	}

	if (i > j) {
		*colEnd = *colStart;
		*rowEnd = *rowStart + i - 1;
	} else {
		*rowEnd = *rowStart;
		*colEnd = *colStart + j - 1;
	}
}

int MoveCar(int road[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1)
{
	int finished = 0;
	if (r0 == r1) {
		// horizontal
		int i = 1;
		int j = 1;
		while (road[r0][c0 - i] == SPACE)
		{
			i++;
		}
		while (road[r1][c1 + j] == SPACE)
		{
			j++;
		}

		if (i - 1 > 0)
		{
			for (int k = c0; k <= c1; k++)
			{
				road[r0][k - i + 1] = road[r0][k];
				road[r0][k] = SPACE;
			}

			if (road[r0][c0 - i] == EXIT)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			for (int k = c1; k >= c0; k--)
			{
				road[r0][k + j - 1] = road[r0][k];
				road[r0][k] = SPACE;
			}

			if (road[r0][c1 + j] == EXIT)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
	} else if (c0 == c1) {
		//vertical
		int i = 1;
		int j = 1;
		while (road[r0-i][c0] == SPACE)
		{
			i++;
		}
		while (road[r1+j][c1] == SPACE)
		{
			j++;
		}

		if (i - 1 > 0) {
			for (int k = r0; k <= r1; k++) {
				road[k-i+1][c0] = road[k][c0];
				road[k][c0] = SPACE;
			}

			if (road[r0 - i][c0] == EXIT)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		} else {
			for (int k = r1; k >= r0; k--)
			{
				road[k + j - 1][c0] = road[k][c0];
				road[k][c0] = SPACE;
			}
			if (road[r1 + j][c0] == EXIT)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}	


/***********************************************************/
/***********************************************************/
/******* A SIMPLE MAIN FUNCTION TO TEST YOUR PROGRESS ******/
/***********************************************************/
/***********************************************************/

void task1(void) {
	int road[NUM_ROWS][NUM_COLS];
	InitialiseRoad(road, 'E', 3);
}

void task2(void) {
	int road[NUM_ROWS][NUM_COLS];
	InitialiseRoad(road, 'E', 3);

	PrintRoad(road);
}

void task3(void) {
	int road[NUM_ROWS][NUM_COLS];
	InitialiseRoad(road, 'E', 3);

	PrintRoad(road);
	printf("Percent used: %f\n", PercentUsed(road));
}

void task4(void) {
	int road[NUM_ROWS][NUM_COLS];

	InitialiseRoad(road, 'E', 3);
	AddCar(road, 3, 1, 2);
	AddCar(road, 2, 4, -4);
	AddCar(road, 5, 3, 3);
	AddCar(road, 6, 3, 3);
	PrintRoad(road);
	printf("Percent used: %f\n", PercentUsed(road));
}

void task5(void) {
	int road[NUM_ROWS][NUM_COLS];
	int rowA, colA, rowB, colB;
	FindCar(road, 'A', &rowA, &colA, &rowB, &colB);
	printf("Car A is at: (%d, %d) - (%d, %d)\n", rowA, colA, rowB, colB);
	FindCar(road, 'B', &rowA, &colA, &rowB, &colB);
	printf("Car B is at: (%d, %d) - (%d, %d)\n", rowA, colA, rowB, colB);
	FindCar(road, 'C', &rowA, &colA, &rowB, &colB);
	printf("Car C is at: (%d, %d) - (%d, %d)\n", rowA, colA, rowB, colB);
}

void task6(void)
{
	int road[NUM_ROWS][NUM_COLS];

	int rowA, colA, rowB, colB;
	int result;

	InitialiseRoad(road, 'E', 3);
	AddCar(road, 3, 1, 2);
	AddCar(road, 3, 4, -3);
	printf("\nTask 6\n");
	PrintRoad(road);

	// Move car B
	FindCar(road, 'B', &rowA, &colA, &rowB, &colB);
	result = MoveCar(road, rowA, colA, rowB, colB);
	printf("Result = %d\n", result);

	PrintRoad(road);

	// Move car B
	FindCar(road, 'B', &rowA, &colA, &rowB, &colB);
	result = MoveCar(road, rowA, colA, rowB, colB);
	printf("Result = %d\n", result);

	PrintRoad(road);

	// Move car A
	FindCar(road, 'A', &rowA, &colA, &rowB, &colB);
	result = MoveCar(road, rowA, colA, rowB, colB);
	printf("Result = %d\n", result);

	PrintRoad(road);
}

/* You should add your own tests in here */
int main(void)
{
	task4();
	
	return 0;
}
