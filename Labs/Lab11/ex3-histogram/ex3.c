#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void PrintXs(int howMany) {
	for (int i = 0; i < howMany; i++) {
		printf("X");
	}
}

int main(void)
{
	FILE *fp;
	char filename[200];

	printf("Enter filename:\n");
	scanf("%s", filename);
	fp = fopen(filename, "r");

	// my code
	int score;
	int range[11] = {0};
	int rangeLength = 11;

	while (fscanf(fp, "%d", &score) != EOF)
	{
		if (0 <= score && score < 10) {
			range[0]++;
		}
		else if (10 <= score && score < 20)
		{
			range[1]++;
		}
		else if (20 <= score && score < 30)
		{
			range[2]++;
		}
		else if (30 <= score && score < 40)
		{
			range[3]++;
		}
		else if (40 <= score && score < 50)
		{
			range[4]++;
		}
		else if (50 <= score && score < 60)
		{
			range[5]++;
		}
		else if (60 <= score && score < 70)
		{
			range[6]++;
		}
		else if (70 <= score && score < 80)
		{
			range[7]++;
		}
		else if (80 <= score && score < 90)
		{
			range[8]++;
		}
		else if (90 <= score && score < 100)
		{
			range[9]++;
		}
		else if (score == 100) {
			range[10]++;
		}
	}

	int point = 0;
	for (int i = 0; i < rangeLength; i++) {
		printf("%-3d: ", point);
		PrintXs(range[i]);
		printf("\n");
		point += 10;
	}

	return 0;
}
