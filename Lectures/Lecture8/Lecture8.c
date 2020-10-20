#include<stdio.h>

//Lecture 8

int main(void) 
{
    // scanning files
    FILE *fp;

    char response[100];
    int id;
    
    fp = fopen("testdata.txt", "r");

    printf("File output:\n");

    // loop again to read every line
    // EOF end of file
    while (fscanf(fp, "%d %s", &id, response) != EOF) {
        printf("ID: %d Answers: %s\n", id, response);
    }

        

    fclose(fp);
    return 0;
}