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