#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define WORD_LENGTH 5

int OneLetterDifference(char *word1, char *word2)
{
    // You should correctly complete this function defintion
    // Assume word1 and word2 same length
    int i = 0;
    int differences = 0;
    while (word1[i] != '\0')
    {
        if (word1[i] != word2[i])
        {
            differences++;
        }
        i++;
    }

    if (differences == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void) {
    char word1[WORD_LENGTH] = "able";
    char word2[WORD_LENGTH] = "ably";

    if (OneLetterDifference(word1, word2))
    {
        printf("The words differ by just one character");
    }
    else
    {
        printf("The words do not differ by just one character");
    }
    return 0;
}