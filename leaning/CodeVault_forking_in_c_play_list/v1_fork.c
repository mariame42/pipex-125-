#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int id = fork();
    if (id == 0)
        printf("i am the child process , id = 0 \n");
    else
        printf("i am the main process \n");
}

// 2 to the power of n (the number of prosses if in the number of times calling fork )
// int main(int ac, char **av)
// {
//     fork();
//     fork();
//     fork();
//     fork();
//     printf("Hi \n");
// }

// int main(int ac, char **av)
// {
//     int id = fork();
//     if (id != 0)
//         fork();
//     fork();
//     if (id != 0)
//         fork();
//     printf("Hi \n");
// }