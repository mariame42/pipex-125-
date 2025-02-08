

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

// 2 processes
// 1 / the child process should generate random numbers and send them
// to the parent process
// 2 / parent is going to sum all of the numbers and
// return the result


int main(int ac, char **av)
{
    int fd[2];
    int p1 = pipe(fd);
    // p1[0] = read // p1[1] =  write 
    
    if (p1 == -1)
        printf("pipe error\n");
    int pid = fork();
    if (pid == - 1)
        printf("i am an error from fork function\n");

    if (pid == 0)
    {
        close(fd[0]);
        int n;
        int arr[10];
        srand(time(NULL));
        n = rand() % 10 + 1;
        int i = 0;
        while (i < n)
        {
            arr[i] = rand() % 5 + 1;
            printf("arr[%d] = %d\n", i , arr[i]);
            i++;
        }
        i = 0;
        int sum = 0;
        while (i < n)
        {
            printf("%d+", arr[i]);
            sum += arr[i];
            i++;
        }
        printf("=%d\n", sum);
        if (write(fd[1], &n, sizeof(n)) == -1)
            return (4);
        if (write(fd[1], arr, sizeof(int) * n) < 0)
            return (3);
        close(fd[1]);
    }   
    else
    {
        close (fd[1]);
        int arr[10];
        int n;

        if (read(fd[0], &n, sizeof(int)) < 0)
            return 5;
        if (read(fd[0], arr, sizeof(int) * n) < 0)
            return 6;
        close (fd[0]);
        int i = 0;
        int sum = 0;
        while (i < n)
        {
            sum += arr[i];
            i++;
        }
        printf("result:   %d\n", sum);
        wait(NULL);
    }
}