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

    // check through horizontal and vertically, safer but slower
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

void AddCar(int road[NUM_ROWS][NUM_COLS], int row, int col, int size)
{
    int hori, vert, loop;
    int spaces = 0;

    int carName = 64; // allocating first carName to 65

    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (road[i][j] > carName)
            {
                carName = road[i][j];
            }
        }
    }

    carName++;

    if (size > 0) // horizontal check spaces
    {
        for (loop = 0; loop < size; loop++)
        {
            if (road[row][col + loop] == 0)
                spaces++;
        }
        if (spaces == size)
        {
            road[row][col] = carName;
            for (loop = 0; loop < size; loop++)
            {
                road[row][col + loop] = road[row][col];
            }
        }
    }

    else if (size < 0)
    {
        for (loop = size + 1; loop <= 0; loop++)
        {
            if (road[row - loop][col] == 0)
                spaces++;
        }
        if (-spaces == size)
        {
            road[row][col] = carName;
            for (loop = size + 1; loop <= 0; loop++)
            {
                road[row - loop][col] = road[row][col];
            }
        }
    }
}

int MoveCar(int road[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1)
{
    if (r0 == r1) // if condition is true the car is moving horizontally
    {
        if (road[r0][c0 - 1] == SPACE) // condition to move left
        {
            for (int i = 1; road[r0][c0 - i] == SPACE; i++) // if there is space to the left, overwrite with the car's letter and clear the right-most to space
            {
                road[r0][c0 - i] = road[r0][c0 - i + (c1 - c0 + 1)];
                road[r0][c0 - i + (c1 - c0 + 1)] = SPACE;
            }
        }
        else // if there is no space to the left
        {

            for (int i = 1; road[r1][c1 + i] == SPACE; i++) // if there is space to the right, overwrite with the car's letter and clear the left-most to space
            {
                road[r1][c1 + i] = road[r1][c1 + i - (c1 - c0 + 1)];
                road[r1][c1 + i - (c1 - c0 + 1)] = SPACE;
            }
        }
    }

    else if (c0 == c1) // if condition is true the car is moving vertically
    {
        if (road[r0 - 1][c0] == SPACE) // condition to move up
        {
            for (int i = 1; road[r0 - i][c0] == SPACE; i++) // if there is space above, overwrite with the car's letter and clear the bottom-most to space
            {
                road[r0 - i][c0] = road[r0 - i + (r1 - r0 + 1)][c0];
                road[r0 - i + (r1 - r0 + 1)][c0] = SPACE;
            }
        }
        else // if there is no space above
        {

            for (int i = 1; road[r1 + i][c1] == SPACE; i++) // if there is space below, overwrite with the car's letter and clear the upper-most to space
            {
                road[r1 + i][c1] = road[r1 + i - (r1 - r0 + 1)][c1];
                road[r1 + i - (r1 - r0 + 1)][c1] = SPACE;
            }
        }
    }

    for (int row = 0; row < NUM_ROWS; row++) // looping through all elements in the grid
    {
        for (int col = 0; col < NUM_COLS; col++)
        {
            if (road[row][col] == EXIT) // determining when the exit has been reached
            {
                if (row == 0)
                {
                    if (road[row + 1][col] != SPACE && road[row + 2][col] == road[row + 1][col]) // if the car facing the direction of exit is at right by the exut, return 1
                    {
                        return 1;
                    }
                }
                else if (row == NUM_ROWS - 1)
                {
                    if (road[row - 1][col] != SPACE && road[row - 2][col] == road[row - 1][col]) // if the car facing the direction of exit is at right by the exut, return 1
                    {
                        return 1;
                    }
                }
                else if (col == 0)
                {
                    if (road[row][col + 1] != SPACE && road[row][col + 2] == road[row][col + 1]) // if the car facing the direction of exit is at right by the exut, return 1
                    {
                        return 1;
                    }
                }
                else if (col == NUM_COLS - 1)
                {
                    if (road[row][col - 1] != SPACE && road[row][col - 2] == road[row][col - 1]) // if the car facing the direction of exit is at right by the exut, return 1
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}