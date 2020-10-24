#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 8
#define NUM_COLS 8

#define SPACE 0
#define WALL -1
#define EXIT -2

// todo refinement checklist
// InitialiseRoad [x]
// PrintRoad [x]
// PercentUsed [x]
// AddCar [x]
// FindCar [x]
// MoveCar [x]

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
	int occupiedCount = 0;
	for (int i = 1; i < NUM_ROWS - 1; i++) {
		for (int j = 1; j < NUM_COLS - 1; j++) {
			if (road[i][j] != SPACE) {
				occupiedCount++;
			}
		}
	}
	
	int totalSpace = (NUM_ROWS - 2) * (NUM_COLS - 2);
	return ((double) occupiedCount / totalSpace) * 100;
}

void AddCar(int road[NUM_ROWS][NUM_COLS], int row, int col, int size)
{
	// find the highest character
	char highestLetter = 'A' - 1;
	for (int i = 1; i < NUM_ROWS-1; i++) {
		for (int j = 1; j < NUM_COLS-1; j++) {
			if (road[i][j] >= 'A' && road[i][j] <= 'Z' && road[i][j] > highestLetter) {
				highestLetter = road[i][j];
			} 
		}
	}

	// check if horizontal or vertical placement
	if (size < 0) {
		// check for space
		for (int i = row; i < row - size; i++) {
			if (road[i][col] != SPACE) {
				return;
			}
		}

		// if possible place car
		for (int i = row; i < row - size; i++)
		{
			road[i][col] = highestLetter + 1;
		}
	} else if (size > 0) {
		// check for space
		for (int j = col; j < col + size; j++) {
			if (road[row][j] != SPACE) {
				return;
			}	
		}

		// if possible place car
		for (int j = col; j < col + size; j++)
		{
			road[row][j] = highestLetter + 1;
		}
	}
}

void FindCar(int road[NUM_ROWS][NUM_COLS], char move, int *rowStart, int *colStart, int *rowEnd, int *colEnd)
{
	// find starting position
	int startFound = 0;
	for (int i = 1; i < NUM_ROWS-1; i++) {
		for (int j = 1; j < NUM_COLS-1; j++) {
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

	// check if horizontal or vertical
	if (road[*rowStart + 1][*colStart] == move) {
		// count distance to end
		int dist = 0;
		while (road[*rowStart + dist + 1][*colStart] == move) { dist++; }

		*rowEnd = *rowStart + dist;
		*colEnd = *colStart;
	} 
	else {
		int dist = 0;
		while (road[*rowStart][*colStart + dist + 1] == move) { dist++; }

		*rowEnd = *rowStart;
		*colEnd = *colStart + dist;
	}
}

int MoveCar(int road[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1)
{
	int finished = 0;
	if (r0 == r1) {
		// therefore horizontal

		// move left or right
		if (road[r0][c0 - 1] == SPACE) {
			int dist = 0;
			while (road[r0][c0 - dist - 1] == SPACE) { dist++; }

			for (int k = c0; k <= c1; k++)
			{
				road[r0][k - dist] = road[r0][k];
				road[r0][k] = SPACE;
			}

			if (road[r0][c0 - dist - 1] == EXIT) { return 1; }
		}
		else {
			int dist = 0;
			while (road[r1][c1 + dist + 1] == SPACE) { dist++; }

			for (int k = c1; k >= c0; k--)
			{
				road[r0][k + dist] = road[r0][k];
				road[r0][k] = SPACE;
			}

			if (road[r0][c1 + dist + 1] == EXIT) { return 1; }
		}
	} else if (c0 == c1) {
		// therefore vertical
		
		// move up or down 
		if (road[r0 - 1][c0] == SPACE) {
			int dist = 0;
			while (road[r0 - dist - 1][c0] == SPACE) { dist++; }

			for (int k = r0; k <= r1; k++) {
				road[k - dist][c0] = road[k][c0];
				road[k][c0] = SPACE;
			}

			if (road[r0 - dist - 1][c0] == EXIT) { return 1; }
		}
		else {
			int dist = 0;
			while (road[r1 + dist + 1][c1] == SPACE) { dist++; }

			for (int k = r1; k >= r0; k--) {
				road[k + dist][c0] = road[k][c0];
				road[k][c0] = SPACE;
			}
			
			if (road[r1 + dist + 1][c0] == EXIT) { return 1; }
		}
	}
	return 0;
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

	InitialiseRoad(road, 'E', 3);
	AddCar(road, 3, 1, 2);
	AddCar(road, 2, 4, -4);
	AddCar(road, 5, 3, 3);
	AddCar(road, 6, 3, 3);
	PrintRoad(road);
	printf("Percent used: %f\n", PercentUsed(road));
	FindCar(road, 'A', &rowA, &colA, &rowB, &colB);
	printf("Car A is at: (%d, %d) - (%d, %d)\n", rowA, colA, rowB, colB);
	FindCar(road, 'B', &rowA, &colA, &rowB, &colB);
	printf("Car B is at: (%d, %d) - (%d, %d)\n", rowA, colA, rowB, colB);
	FindCar(road, 'C', &rowA, &colA, &rowB, &colB);      
	printf("Car C is at: (%d, %d) - (%d, %d)\n", rowA, colA, rowB, colB);
}

void task5Extra(void) {
	int road[NUM_ROWS][NUM_COLS];
	int rowA, colA, rowB, colB;

	InitialiseRoad(road, 'E', 3);
	AddCar(road, 1, 1, 6);
	AddCar(road, 2, 1, 6);
	AddCar(road, 3, 1, 6);
	AddCar(road, 4, 1, 6);
	PrintRoad(road);
	printf("Percent used: %f\n", PercentUsed(road));

	FindCar(road, 'A', &rowA, &colA, &rowB, &colB);
	printf("Car A is at: (%d, %d) - (%d, %d)\n", rowA, colA, rowB, colB);
	FindCar(road, 'B', &rowA, &colA, &rowB, &colB);
	printf("Car B is at: (%d, %d) - (%d, %d)\n", rowA, colA, rowB, colB);
	FindCar(road, 'C', &rowA, &colA, &rowB, &colB);
	printf("Car C is at: (%d, %d) - (%d, %d)\n", rowA, colA, rowB, colB);
	FindCar(road, 'D', &rowA, &colA, &rowB, &colB);
	printf("Car D is at: (%d, %d) - (%d, %d)\n", rowA, colA, rowB, colB);
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

void task7(void) {
	// change numRows: 7 numCols: 18
	int road[NUM_ROWS][NUM_COLS];
	InitialiseRoad(road, 'S', 6);
	AddCar(road, 2, 6, -3);
	AddCar(road, 4, 14, -2);
	AddCar(road, 5, 3, 9);
	PrintRoad(road);
}


/* You should add your own tests in here */
int main(void)
{
	task6();
	
	return 0;
}
