#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int ac , char **av)
{
    int arr[] = {1, 2, 3, 4, 1, 2, 5, 18};
    int size = sizeof(arr) / sizeof(int);
    int start, end;
    int fd[2];
    if (pipe(fd) == -1)
        return 1;

    int id = fork();
    if (id == -1)
        return (2);
    
    if (id == 0)
    {
        start = 0;
        end = start + size / 2;
    }
    else
    {
        start = size / 2;
        end = size;
    }

    int sum = 0;
    int i;
    for (i = start; i < end; i++)
        sum += arr[i];
    printf("calc: %d\n", sum);

    if (id == 0){
        close(fd[0]);
        write (fd[1], &sum, sizeof(sum));
        close(fd[1]);
    }
    else{
        close (fd[1]);
        int sumFromChild;
        read(fd[0], &sumFromChild, sizeof(sumFromChild));
        close (fd[0]);

        int totalSum = sum + sumFromChild;
        printf("tot: %d\n", totalSum);
        wait(NULL);
    }


}