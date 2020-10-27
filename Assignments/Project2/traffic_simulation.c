#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 8
#define NUM_COLS 8

#define SPACE 0
#define WALL -1
#define EXIT -2

/***********************************************************/
/***********************************************************/
/******* ADD THE REQUIRED FUNCTIONS BELOW THIS POINT *******/
/***********************************************************/
/***********************************************************/

// Your function definitions should go here...

// InitialiseRoad function generates the game board within road array
// Inputs:
// (int) road[NUM_ROWS][NUM_COLS], empty array size NUM_ROWS by NUM_COlS
// (char) side, ('N', 'E', 'W', 'S') north, east, west or south direction of exit
// (int) pos, rows down from top or columns across from left where exit should be.
// Ouput: (void)
// Author: Matthew Ouyang

void InitialiseRoad(int road[NUM_ROWS][NUM_COLS], char side, int pos)
{
	// build walls and spaces
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			// outer most layer will be the WALL
			// everything within will be the SPACE
			if (i == 0 || i == NUM_ROWS - 1 || j == 0 || j == NUM_COLS - 1)
			{
				road[i][j] = WALL;
			}
			else
			{
				road[i][j] = SPACE;
			}
		}
	}

	// add the exit depending on side
	if (side == 'N')
	{
		road[0][pos] = EXIT;
	}
	else if (side == 'E')
	{
		road[pos][NUM_COLS - 1] = EXIT;
	}
	else if (side == 'W')
	{
		road[pos][0] = EXIT;
	}
	else
	{
		road[NUM_ROWS - 1][pos] = EXIT;
	}
}

// PrintRoad function outputs the game board into console
// Input: (int) road[NUM_ROWS][NUM_COLS], populated array of game components
// Ouput: (void)
// Author: Matthew Ouyang

void PrintRoad(int road[NUM_ROWS][NUM_COLS])
{
	// scan through road, and print out tiles depending on what it is
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			if (road[i][j] == WALL)
			{
				printf("%c", '#');
			}
			else if (road[i][j] == SPACE)
			{
				printf("%c", ' ');
			}
			else if (road[i][j] == EXIT)
			{
				printf("%c", 'O');
			}
			else
			{
				printf("%c", road[i][j]);
			}
		}
		// start of new row
		printf("\n");
	}
}

// PercentUsed function calculates the percentage of space occupied
// Input: (int) road[NUM_ROWS][NUM_COLS], populated array of game components
// Output: (double) percentage of space occupied
// Author: Matthew Ouyang

double PercentUsed(int road[NUM_ROWS][NUM_COLS])
{
	// scan through road array and count number of occupied space
	int occupiedCount = 0;
	for (int i = 1; i < NUM_ROWS - 1; i++)
	{
		for (int j = 1; j < NUM_COLS - 1; j++)
		{
			if (road[i][j] != SPACE)
			{
				occupiedCount++;
			}
		}
	}

	// calculate the total possible space
	int totalSpace = (NUM_ROWS - 2) * (NUM_COLS - 2);

	// return percentage of space used
	return ((double)occupiedCount / totalSpace) * 100;
}

// AddCar function places car tiles into the road array if possible
// Inputs:
// (int) road[NUM_ROWS][NUM_COLS], populated array of game components
// (int) row, starting row position of car
// (int) col, starting column position of car
// (int) size, number of spaces the car occupies, positive means horizontal
// and negative vertical
// Output: (void)
// Author: Matthew Ouyang

void AddCar(int road[NUM_ROWS][NUM_COLS], int row, int col, int size)
{
	// find the highest character currently in road array
	char highestLetter = 'A' - 1;
	for (int i = 1; i < NUM_ROWS - 1; i++)
	{
		for (int j = 1; j < NUM_COLS - 1; j++)
		{
			if (road[i][j] >= 'A' && road[i][j] <= 'Z' && road[i][j] > highestLetter)
			{
				highestLetter = road[i][j];
			}
		}
	}

	// check orientation
	if (size < 0)
	{
		// vertical, check for space, if not possible just return
		for (int i = row; i < row - size; i++)
		{
			if (road[i][col] != SPACE)
			{
				return;
			}
		}

		// if possible place the car
		for (int i = row; i < row - size; i++)
		{
			road[i][col] = highestLetter + 1;
		}
	}
	else if (size > 0)
	{
		// horizontal, check for space, if not possible just return
		for (int j = col; j < col + size; j++)
		{
			if (road[row][j] != SPACE)
			{
				return;
			}
		}

		// if possible place the car
		for (int j = col; j < col + size; j++)
		{
			road[row][j] = highestLetter + 1;
		}
	}
}

// FindCar function searches for a specific car's location in road array
// Inputs:
// (int) road[NUM_ROWS][NUM_COLS], populated array of game components
// (char) move, alphabetical character of car we want to find
// (int) rowStart, pointer for starting row of car
// (int) colStart, pointer for starting column of car
// (int) rowEnd, pointer for row end of car
// (int) colEnd, pointer for column end of car
// Output: (void)
// Author: Matthew Ouyang

void FindCar(int road[NUM_ROWS][NUM_COLS], char move, int *rowStart, int *colStart, int *rowEnd, int *colEnd)
{
	// look through road array
	int startFound = 0;
	for (int i = 1; i < NUM_ROWS - 1; i++)
	{
		for (int j = 1; j < NUM_COLS - 1; j++)
		{
			// first occurence of the car will be it's start position
			if (road[i][j] == move && startFound == 0)
			{
				*rowStart = i;
				*colStart = j;
				startFound = 1;
			}
			// final occurence of car will be it's end position
			else if (road[i][j] == move)
			{
				*rowEnd = i;
				*colEnd = j;
			}
		}
	}
}

// MoveCar function moves a specified car back and forth and checks if exit reached
// Inputs:
// (int) road[NUM_ROWS][NUM_COLS], populated array of game components
// (int) r0, starting row of car
// (int) c0, starting column of car
// (int) r1, row end of car
// (int) c1, column end of car
// Output: (int) 1 if exit reached, else 0 if exit not reached
// Author: Matthew Ouyang

int MoveCar(int road[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1)
{
	// check orientation
	if (r0 == r1)
	{
		// therefore horizontal
		// check if it can move left or right
		// prioritise left first
		if (road[r0][c0 - 1] == SPACE)
		{
			// move car left
			int i = 1;
			for (i; road[r0][c0 - i] == SPACE; i++)
			{
				road[r0][c0 - i] = road[r0][c1 - (i - 1)];
				road[r0][c1 - (i - 1)] = SPACE;
			}

			// check if it bumped an exit
			if (road[r0][c0 - i] == EXIT)
			{
				return 1;
			}
		}
		else
		{
			// move car right
			int i = 1;
			for (i; road[r0][c1 + i] == SPACE; i++)
			{
				road[r0][c1 + i] = road[r0][c0 + (i - 1)];
				road[r0][c0 + (i - 1)] = SPACE;
			}
			// check if it bumped an exit
			if (road[r0][c1 + i] == EXIT)
			{
				return 1;
			}
		}
	}
	else if (c0 == c1)
	{
		// therefore vertical
		// check if it can move up or down
		// prioritise up first
		if (road[r0 - 1][c0] == SPACE)
		{
			// move car up
			int i = 1;
			for (i; road[r0 - i][c0] == SPACE; i++)
			{
				road[r0 - i][c0] = road[r1 - (i - 1)][c0];
				road[r1 - (i - 1)][c0] = SPACE;
			}

			// check if it bumped an exit
			if (road[r0 - i][c0] == EXIT)
			{
				return 1;
			}
		}
		else
		{
			// move car down
			int i = 1;
			for (i; road[r1 + i][c0] == SPACE; i++)
			{
				road[r1 + i][c0] = road[r0 + (i - 1)][c0];
				road[r0 + (i - 1)][c0] = SPACE;
			}

			// check if it bumped an exit
			if (road[r1 + i][c0] == EXIT)
			{
				return 1;
			}
		}
	}

	return 0;
}

/***********************************************************/
/***********************************************************/
/********* DO NOT MODIFY ANY CODE BELOW THIS POINT *********/
/***********************************************************/
/***********************************************************/

/* Function to obtain capital letter as input */
char GetMove(void)
{
	char move;
	printf("\nMove car: ");
	scanf("%c", &move);
	// Ignore non-capital letter inputs
	while ((move < 'A') || (move > 'Z')) {
		scanf("%c", &move);
	}
	return move;
}

/* The main Traffic Jam simulation */
int main(void)
{
	int gameOver = 0;
	int road[NUM_ROWS][NUM_COLS];
	int rowStart, colStart, rowEnd, colEnd;
	char input;

	/* Print banner */
	printf(" _____           __  __ _            _                                        \n");
	printf("|_   _| __ __ _ / _|/ _(_) ___      | | __ _ _ __ ___           ____          \n");
	printf("  | || '__/ _` | |_| |_| |/ __|  _  | |/ _` | '_ ` _ \\  --   __/  |_\\_      \n");
	printf("  | || | | (_| |  _|  _| | (__  | |_| | (_| | | | | | | --- |  _     _``-.    \n");
	printf("  |_||_|  \\__,_|_| |_| |_|\\___|  \\___/ \\__,_|_| |_| |_| --  '-(_)---(_)--'\n\n");

	/* Initialise the road and add cars */
	InitialiseRoad(road, 'E', 3);
	AddCar(road, 3, 3, 2);
	AddCar(road, 1, 1, 2);
	AddCar(road, 2, 1, 3);
	AddCar(road, 3, 2, -2);
	AddCar(road, 5, 2, -2);
	AddCar(road, 4, 4, -2);
	AddCar(road, 6, 3, 3);
	AddCar(road, 1, 5, -3);
	AddCar(road, 2, 6, -2);

	/* Print status */
	printf("ENGGEN131 2020 - C Project\nTraffic Jam!  There is a lot of traffic on the road!\n");
	printf("In fact, %.2f%% of the road is cars!\n\n", PercentUsed(road));

	/* Main simulation loop */
	while (!gameOver) {
		PrintRoad(road);
		input = GetMove();
		FindCar(road, input, &rowStart, &colStart, &rowEnd, &colEnd);
		gameOver = MoveCar(road, rowStart, colStart, rowEnd, colEnd);
	}

	/* A car has exited - the simulation is over */
	PrintRoad(road);
	printf("\nCongratulations, you're on your way again!");

	return 0;
}
