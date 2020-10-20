#define _CRT_SECURE_NO_WARNINGS

/* A word game where each player must substitute one letter in a word to generate a new word */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* The dictionary we are using has fewer than 2500 words */
#define MAX_WORDS 2500
#define WORD_LENGTH 5

/* Function prototype declarations */
void RemoveFromWordList(int index, char *word);
int GetStartingWordIndex(void);
int GetNextWord(int computer, char *word);
int WordsRemaining(char *word, int cheat);
int RandomBetween(int a, int b);
void InitialiseWordList(void);
int GetWordFromUser(void);
int OneLetterDifference(char *word1, char *word2);
int PlayOneTurn(int cheat, char *word, int computerTurn);
int GetCheatChoice();

/* GLOBAL VARIABLES - the list of words of a given length, and the number of words in the list */
char wordList[MAX_WORDS][WORD_LENGTH];
int numWords;

/********************************************************************************/
/********************************************************************************/
/******** This is the only function you need to define for this exercise ********/
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
/* Returns true if there is exactly one letter difference between the two words */
int OneLetterDifference(char *word1, char *word2)
{
	// You should correctly complete this function defintion
	// Assume word1 and word2 same length
	int i = 0;
	int differences = 0;
	while (word1[i] != '\0') {
		if (word1[i] != word2[i]) {
			differences++;
		}
		i++;
	}

	if (differences == 1) {
		return 1;
	} else {
		return 0;
	}
}
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/




/* Prompts the user to enter a word and confirms that it exists amongst the remaining words */
int GetWordFromUser(void)
{
	int i;
	char word[WORD_LENGTH];

	printf("Your word:     ");
	scanf("%s", word);

	for (i = 0; i < numWords; i++) {
		if (strcmp(wordList[i], word) == 0) {
			return i;
		}
	}

	return -1;
}

/* The main function for the proram */
int main(void)
{
	int wordIndex;
	char word[WORD_LENGTH];
	int gameOver = 0;
	int computerTurn = 0;
	int cheat = 0;

	// Set the seed for the random number generator
	srand((unsigned int)time(NULL));

	// Check if the user wants to see a list of allowed words
	cheat = GetCheatChoice();

	// Initialise list of words
	InitialiseWordList();

	// Choose a starting word for the game
	wordIndex = GetStartingWordIndex();
	printf("Starting word: %s\n", wordList[wordIndex]);
	RemoveFromWordList(wordIndex, word);

	// Continue playing, alternating players, until the game is over
	while (!gameOver) {
		gameOver = PlayOneTurn(cheat, word, computerTurn);
		computerTurn = 1 - computerTurn;
	}

	return 0;
}

/* Process the turn for one player, either the computer or the human.  This function returns true
   if the game is over, otherwise it returns false */
int PlayOneTurn(int cheat, char *word, int computerTurn)
{
	int wordsRemaining, wordIndex;

	wordsRemaining = WordsRemaining(word, cheat && !computerTurn);
	if (cheat) {
		printf("Words remaining: %d\n", wordsRemaining);
	}
	if (wordsRemaining == 0) {
		printf("No more words... game over.\n");
		if (computerTurn) {
			printf("\nYOU WIN!!\n");
		} else {
			printf("\nComputer wins.\n");
		}
		return 1;
	} else {
		wordIndex = GetNextWord(computerTurn, word);
		if (computerTurn) {
			printf("Computer word: %s\n", wordList[wordIndex]);
		}
		RemoveFromWordList(wordIndex, word);
	}
	return 0;
}

/* Prompts the user if they would like to cheat */
int GetCheatChoice()
{
	char input[WORD_LENGTH];
	printf("Do you want to cheat? (yes/no): ");
	scanf("%s", input);
	if (input[0] == 'y' || input[0] == 'Y')
		return 1;
	else
		return 0;
}

/* Removes a word from the list of available words */
void RemoveFromWordList(int index, char *word)
{
	strcpy(word, wordList[index]);
	strcpy(wordList[index], wordList[numWords-1]);
	numWords--;
}

/* Selects a random index for the starting word */
int GetStartingWordIndex(void)
{
	return RandomBetween(0, numWords-1);
}

/* Processes either the computer or the humans choice.  The computer chooses a random
   word from those available, and the humans words is validated */
int GetNextWord(int computer, char *word)
{
	int indices[MAX_WORDS] = {0};
	int numIndices = 0;
	int i;

	if (computer) {
		for (i = 0; i < numWords; i++) {
			if (OneLetterDifference(wordList[i], word)) {
				indices[numIndices] = i;
				numIndices++;
			}
		}

		if (numIndices == 0)
			return -1;
		else
			return indices[RandomBetween(0, numIndices-1)];
	} else {
		do {
			i = GetWordFromUser();
		} while ((i == -1) || (OneLetterDifference(wordList[i], word) != 1));
		return i;
	}
}

/* Calculates how many valid words are remaining in the list.  If this function
   returns 0 then the game will be over */
int WordsRemaining(char *word, int cheat)
{
	int indices[MAX_WORDS] = {0};
	int numIndices = 0;

	int i;
	if (cheat) {
		printf("[ ");
	}
	for (i = 0; i < numWords; i++) {
		if (OneLetterDifference(wordList[i], word)) {
			if (cheat) {
				printf("%s ", wordList[i]);
			}
			indices[numIndices] = i;
			numIndices++;
		}
	}
	if (cheat) {
		printf("]\n");
	}

	return numIndices;
}

/* Returns a random integer between a and b inclusive */
int RandomBetween(int a, int b)
{
	return (rand() % (b-a+1)) + a;
}

/* Reads all of the words from the dictionary file, and stores those of the appropriate length into memory */
void InitialiseWordList(void)
{
	FILE *inputFile;
	char word[WORD_LENGTH];

	inputFile = fopen("wordlist.txt", "r");
	numWords = 0;

	if(inputFile == NULL) {
		printf("Could not open file.");
		exit(EXIT_FAILURE);
	}

	while (fscanf(inputFile, "%s", word) != EOF) {
		strcpy(wordList[numWords], word);
		numWords++;
	}

	printf("%d words read from file.\n", numWords);
}
