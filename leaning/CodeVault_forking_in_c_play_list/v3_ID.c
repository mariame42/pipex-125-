#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int ac, char **av)
{
    int id = fork();
    // if (id != 0)
    //     wait(NULL);
    printf("%d:  \n", id);
    printf("current ID: %d, parent ID: %d\n", getpid(), getppid());
    int res = wait(NULL);
    if (res == -1)
        printf("no children to wait for\n");
    else // show the process that it wait for
        printf("%d finished execution\n", res);
    
}

/*
the return value of fork : id : the id of my child if i dont have i will return 0
the return value of getpid : this is my ID
the return value of getppid : this is my parent ID if my parent execute first i will return 1
*/