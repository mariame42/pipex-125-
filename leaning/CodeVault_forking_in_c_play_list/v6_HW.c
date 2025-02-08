#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int ac, char **av)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    int start, end;
    int fd[2];
    if (pipe(fd) == -1)
        return 1;
    
    int id1 = fork();
    int id2;
    if (id1 != 0)
    { 
        id2 = fork();
    }

    if (id1 == 0)
    {
        start = 0;
        end = 2;
    }
    else if (id2 == 0)
    {
        start = 3;
        end = 5;
    }
    else
    {
        start = 6;
        end = 8;
    }
    int i = start;
    int sum = 0;
    while (i <= end)
    {
        sum += arr[i];
        i++;
    }
    printf("sum:  %d\n", sum);

    if (id1 == 0)
    {
        close(fd[0]);
        write (fd[1], &sum, sizeof(sum));
        close(fd[1]);
    }
    else if (id2 == 0)
    {
        close(fd[0]);
        write (fd[1], &sum, sizeof(sum));
        close(fd[1]);
    }
    else
    {
        close (fd[1]);
        int child1;
        int child2;
        read(fd[0], &child1, sizeof(child1));
        read(fd[0], &child2, sizeof(child2));

        int tot = child1 + child2 + sum;
        printf("tot: %d\n", tot);
        wait(NULL);
    }

}