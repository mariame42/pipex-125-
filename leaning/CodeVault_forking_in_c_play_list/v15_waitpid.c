#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main(int ac, char **av)
{
    int pid1 = fork();
    if (pid1 == -1)
        return 1;
    if (pid1 == 0)
    {
        sleep(4);
        printf("1: finished execution : %d\n", getpid());
        return 0;
    }
    int pid2 = fork();
    if (pid2 == -1)
        return 2;
    if (pid2 == 0)
    {
        sleep(1);
        printf("2: finish execution : %d\n", getpid());
        return (0);
    }
    int pid1_res = waitpid(pid1, NULL, 0);
    printf("waited for %d\n", pid1_res);
    int pid2_res = waitpid(pid2, NULL, 0);
    printf("waited for %d\n", pid2_res);
}

// waitpid(pid1, NULL, WNOHANG);