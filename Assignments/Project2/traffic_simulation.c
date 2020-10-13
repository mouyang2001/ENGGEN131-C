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
	else if (side == 'S')
	{
		road[NUM_ROWS - 1][pos] = EXIT;
	}
}

void PrintRoad(int road[NUM_ROWS][NUM_COLS])
{
	int i, j;
	for (i = 0; i < NUM_ROWS; i++)
	{
		for (j = 0; j < NUM_COLS; j++)
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
	int availableSpace = 0;
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			if (road[i][j] == SPACE)
			{
				availableSpace++;
			}
		}
	}
	int totalSpace = (NUM_ROWS - 2) * (NUM_COLS - 2);
	return ((double)(totalSpace - availableSpace) / totalSpace) * 100;
}

void AddCar(int road[NUM_ROWS][NUM_COLS], int row, int col, int size)
{
	// find the highest character
	char highestLetter = 'A' - 1;
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			if (road[i][j] >= 'A' && road[i][j] <= 'Z' && road[i][j] > highestLetter)
			{
				highestLetter = road[i][j];
			}
		}
	}

	// check if horizontal or vertical placement
	int impossible = 0;
	if (size < 0)
	{
		// check for space
		for (int i = row; i < row - size; i++)
		{
			if (road[i][col] != SPACE)
			{
				impossible = 1;
			}
		}

		// if possible place car
		if (impossible == 0)
		{
			for (int i = row; i < row - size; i++)
			{
				road[i][col] = highestLetter + 1;
			}
		}
	}
	else if (size > 0)
	{
		// check for space
		for (int j = col; j < col + size; j++)
		{
			if (road[row][j] != SPACE)
			{
				impossible = 1;
			}
		}

		// if possible place car
		if (impossible == 0)
		{
			for (int j = col; j < col + size; j++)
			{
				road[row][j] = highestLetter + 1;
			}
		}
	}
}

void FindCar(int road[NUM_ROWS][NUM_COLS], char move, int *rowStart, int *colStart, int *rowEnd, int *colEnd)
{
	// find starting position
	int startFound = 0;
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
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

	// find end position first by checking right or down
	int i = 1;
	int j = 1;
	while (road[*rowStart + i][*colStart] == move)
	{
		i++;
	}
	while (road[*rowStart][*colStart + j] == move)
	{
		j++;
	}

	if (i > j)
	{
		*colEnd = *colStart;
		*rowEnd = *rowStart + i - 1;
	}
	else
	{
		*rowEnd = *rowStart;
		*colEnd = *colStart + j - 1;
	}
}

int MoveCar(int road[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1)
{
	int finished = 0;
	if (r0 == r1)
	{
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
	}
	else if (c0 == c1)
	{
		//vertical
		int i = 1;
		int j = 1;
		while (road[r0 - i][c0] == SPACE)
		{
			i++;
		}
		while (road[r1 + j][c1] == SPACE)
		{
			j++;
		}

		if (i - 1 > 0)
		{
			for (int k = r0; k <= r1; k++)
			{
				road[k - i + 1][c0] = road[k][c0];
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
		}
		else
		{
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
