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

void InitialiseRoad(int road[NUM_ROWS][NUM_COLS], char side, int pos)
{
	// build walls and spaces
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
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

	// add exit
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

void PrintRoad(int road[NUM_ROWS][NUM_COLS])
{
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
		printf("\n");
	}
}

double PercentUsed(int road[NUM_ROWS][NUM_COLS])
{
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

	int totalSpace = (NUM_ROWS - 2) * (NUM_COLS - 2);
	return ((double)occupiedCount / totalSpace) * 100;
}

void AddCar(int road[NUM_ROWS][NUM_COLS], int row, int col, int size)
{
	// find the highest character
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

	// check if horizontal or vertical placement
	if (size < 0)
	{
		// check for space
		for (int i = row; i < row - size; i++)
		{
			if (road[i][col] != SPACE)
			{
				return;
			}
		}

		// if possible place car
		for (int i = row; i < row - size; i++)
		{
			road[i][col] = highestLetter + 1;
		}
	}
	else if (size > 0)
	{
		// check for space
		for (int j = col; j < col + size; j++)
		{
			if (road[row][j] != SPACE)
			{
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
	for (int i = 1; i < NUM_ROWS - 1; i++)
	{
		for (int j = 1; j < NUM_COLS - 1; j++)
		{
			if (road[i][j] == move && startFound == 0)
			{
				*rowStart = i;
				*colStart = j;
				startFound = 1;
				break;
			}
		}
		if (startFound == 1)
		{
			break;
		}
	}

	// check if horizontal or vertical
	if (road[*rowStart + 1][*colStart] == move)
	{
		// count distance to end
		int dist = 0;
		while (road[*rowStart + dist + 1][*colStart] == move)
		{
			dist++;
		}

		*rowEnd = *rowStart + dist;
		*colEnd = *colStart;
	}
	else
	{
		int dist = 0;
		while (road[*rowStart][*colStart + dist + 1] == move)
		{
			dist++;
		}

		*rowEnd = *rowStart;
		*colEnd = *colStart + dist;
	}
}

int MoveCar(int road[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1)
{
	int finished = 0;
	if (r0 == r1)
	{
		// therefore horizontal

		// move left or right
		if (road[r0][c0 - 1] == SPACE)
		{
			int dist = 0;
			while (road[r0][c0 - dist - 1] == SPACE)
			{
				dist++;
			}

			for (int k = c0; k <= c1; k++)
			{
				road[r0][k - dist] = road[r0][k];
				road[r0][k] = SPACE;
			}

			if (road[r0][c0 - dist - 1] == EXIT)
			{
				return 1;
			}
		}
		else
		{
			int dist = 0;
			while (road[r1][c1 + dist + 1] == SPACE)
			{
				dist++;
			}

			for (int k = c1; k >= c0; k--)
			{
				road[r0][k + dist] = road[r0][k];
				road[r0][k] = SPACE;
			}

			if (road[r0][c1 + dist + 1] == EXIT)
			{
				return 1;
			}
		}
	}
	else if (c0 == c1)
	{
		// therefore vertical

		// move up or down
		if (road[r0 - 1][c0] == SPACE)
		{
			int dist = 0;
			while (road[r0 - dist - 1][c0] == SPACE)
			{
				dist++;
			}

			for (int k = r0; k <= r1; k++)
			{
				road[k - dist][c0] = road[k][c0];
				road[k][c0] = SPACE;
			}

			if (road[r0 - dist - 1][c0] == EXIT)
			{
				return 1;
			}
		}
		else
		{
			int dist = 0;
			while (road[r1 + dist + 1][c1] == SPACE)
			{
				dist++;
			}

			for (int k = r1; k >= r0; k--)
			{
				road[k + dist][c0] = road[k][c0];
				road[k][c0] = SPACE;
			}

			if (road[r1 + dist + 1][c0] == EXIT)
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
