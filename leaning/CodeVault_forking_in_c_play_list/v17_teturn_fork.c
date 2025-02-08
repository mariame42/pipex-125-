#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main(int ac, char **av)
{
    int id = fork(); // fork return two value 
    // Inside parent peocess :  return the child process id -  it`s going to be different than getpid()
    // Inside child process : return 0 -  it`s going to be different than getpid()
    if (id == 0)
        sleep(1);
    printf("returned by fork: %d, cur ID: %d, parent ID : %d\n", id, getpid(), getppid());

    int res = wait(NULL);

    if (res == -1)
        printf("no children to wait for\n");
    else
        printf("%d finished execution\n", res);
    return 0;
}