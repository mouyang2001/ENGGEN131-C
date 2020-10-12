#include <stdio.h>
#include <string.h>

// lecture 6 strings and random
// NOTE that a%b if a < b then the result is a
// NOTE that division with (int) will floor the answer

int StringLength(char text[]) 
{
    int i = 0;
    while (text[i] != '\0') {
        i++;
    }
    return i;
}

void AllCaps(char text[])
{
    int i = 0;
    while (text[i] != '\0') {
        if ((text[i] >= 'a') && (text[i] <= 'z')) {
            text[i] = text[i] - 32;
        }
        i++;
    }
}

int main(void)
{
    // char greeting[100] = {'h', 'e', 'l', 'l', 'o'}
    // or
    // double quotes "" puts a null character at the end
    char greeting[100] = "hello world";

    //getting string input
    // scanf("%s", greeting);

    int result = StringLength(greeting);
    printf("Length = %d\n", result);

    // print whole char array as string
    printf("Before: %s\n", greeting);
    AllCaps(greeting);
    printf("After: %s\n", greeting);

    // print out individual characters
    printf("First character: %c ascii value: %d\n", greeting[0], greeting[0]);

    return 0;
}