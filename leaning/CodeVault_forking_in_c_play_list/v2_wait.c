#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//print 1 to 10   half with the main and half with the child
// int main(int ac, char **av)
// {
//     int id = fork();
//     int n;
//     if (id == 0)
//         n = 1;
//     else
//         n = 6;
//     int i;
//     for (i = n; i < n + 5; i++)
//     {
//         printf("%d \n", i);
//         fflush(stdout);
//     }

// }

// The behavior of process scheduling can indeed vary between
//  operating systems and even between different implementations within the same OS.

/*using the wait function*/

int main(int ac, char **av)
{
    int id = fork();
    int n;
    if (id == 0)
        n = 1;
    else{
        n = 6;
    }
    if (id != 0)
    {
        int status;
        wait(&status);
    }
    int i;
    for (i = n; i < n + 5; i++)
    {
        printf("%d \n", i);
        fflush(stdout);
    }
    if (id == 0)
        printf("\n");
}
