#include <stdio.h>
#include <string.h>

// EXERCISE 1
// Notes
// loop if return false; violation instant return false
int IsPalindrome(char *word)
{
	// get length of word first
	int j = 0;
	while (word[j] != '\0') {
		j++;
	}

	int i = 0;
	while (word[i] != '\0' && i < j) {
		if (word[i] != word[j-1]) {
			return 0;
		} else {
			i++;
			j--; 
		}
	}
	return 1;
}

// EXERCISE 2
// Notes
// Make sure if char already uppercase don't change it
// Make sure there is a space ' ' before the char i-1
void Capitalise(char *phrase)
{
	int i = 0;
	while (phrase[i] != '\0') {
		if (phrase[i] >= 'a' && phrase[i] <= 'z') {
			if (i == 0) {
				phrase[i] = phrase[i] - 32;
			}
			else if (i > 0 && phrase[i - 1] == ' ') {
				phrase[i] = phrase[i] - 32;
			}
		}
		i++;
	}
}

// EXERCISE 3
// Notes
// first check length of pattern and word is the same
// find the violation to imediate false
int WordMatchesPattern(char *word, char *pattern)
{
	int i = 0;
	while (word[i] != '\0') {
		i++;
	}
	int j = 0;
	while (pattern[j] != '\0') {
		j++;
	}
	if (i != j) {
		return 0;
	} else {
		for (int k = 0; k < i; k++) {
			if (pattern[k] != '-' && word[k] != pattern[k]) {
				return 0;
			}
		}
		return 1;
	}
}

/**************************************************************************************
YOU DO NOT NEED TO MODIFY ANY CODE BELOW HERE.
The code below defines the main() function that *calls* the WordMatchesPattern() function
you must define above.  Feel free to examine the code below, but you should not make
any changes to the following code.
**************************************************************************************/
int main(void)
{

	char word1[100] = "tenet";
	char word2[100] = "not";

	printf("EXERCISE 1\n");
	printf("%d ", IsPalindrome(word1));
	printf("%d ", IsPalindrome(word2));

	printf("\n\nEXERCISE 2\n");
	char song[1000] = "god of nations at thy feet";
	char here[1000] = "The University of Auckland";
	char also[1000] = "a,b,c      888       d!e!f";
	char zzz[1000] = "zzzzz";

	Capitalise(song);
	Capitalise(here);
	Capitalise(also);
	Capitalise(zzz);

	printf("%s \n", song);
	printf("%s \n", here);
	printf("%s \n", also);
	printf("%s \n", zzz);

	printf("\n\nEXERCISE 3\n");

	char word[100] = "apple";
	char pattern[100] = "a-p-e";
	printf("%d ", WordMatchesPattern(word, pattern));

	char worda[100] = "helps";
	char patterna[100] = "hell-";
	printf("%d ", WordMatchesPattern(worda, patterna));

	return 0;
}

