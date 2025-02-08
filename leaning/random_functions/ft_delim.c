#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Hello, world! How are you?";
    char *delim = " ,!?";  // Multiple delimiters: space, comma, exclamation, question mark
    char *token = strtok(str, delim);

}