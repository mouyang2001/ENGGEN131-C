#include <stdio.h>
#include <string.h>

// EXERCISE 1
// Notes
// loop if return false; violation instant return false
int IsPalindrome(char *word)
{

}

// EXERCISE 2
// Notes
// Make sure if char already uppercase don't change it
// Make sure there is a space ' ' before the char i-1
void Capitalise(char *phrase)
{

}

// EXERCISE 3
// Notes
// first check length of pattern and word is the same
// find the violation to imediate false
int WordMatchesPattern(char *word, char *pattern)
{

}

/**************************************************************************************
YOU DO NOT NEED TO MODIFY ANY CODE BELOW HERE.
The code below defines the main() function that *calls* the WordMatchesPattern() function
you must define above.  Feel free to examine the code below, but you should not make
any changes to the following code.
**************************************************************************************/
int main(void)
{

	char word1[100] = "noon";
	char word2[100] = "not";

	printf("EXERCISE 1\n");
	printf("%d ", IsPalindrome(word1));
	printf("%d ", IsPalindrome(word2));

	printf("\n\nEXERCISE 2\n");
	char song[1000] = "god of nations at thy feet";
	char here[1000] = "The University of Auckland";
	char also[1000] = "a,b,c      888       d!e!f";

	Capitalise(song);
	Capitalise(here);
	Capitalise(also);

	printf("%s \n", song);
	printf("%s \n", here);
	printf("%s \n", also);

	printf("\n\nEXERCISE 3\n");

	char word[100] = "apple";
	char pattern[100] = "a-p-e";
	printf("%d", WordMatchesPattern(word, pattern));

	return 0;
}

