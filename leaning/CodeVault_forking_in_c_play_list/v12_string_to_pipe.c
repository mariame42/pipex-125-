#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main(int ac, char **av)
{
    int fd[2];
    if (pipe(fd) == -1)
        return 1;
    
    int pid = fork();
    if (pid == -1)
        return 2;
    if (pid == 0)
    {
        close(fd[0]);
        // child process
        char str[256];
        printf("input string: ");
        fgets(str, 200, stdin);
        str[strlen(str)] = '\0';  // put null at the end
        int len = strlen(str) + 1;
        if (write(fd[1], &len, sizeof(int)) == -1)
            return 3;
        if (write(fd[1], str,sizeof(char) *  (strlen(str) + 1)) == -1)
            return 4;
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        char str[256];
        int len;
        if (read(fd[0], &len, sizeof(int)) == -1)
            return 5;
        if (read(fd[0], str, sizeof(char) * len) == -1)
            return 6;
        int i = 0;
        printf("the string is : %s", str);
        close(fd[0]);
        wait(NULL);
    }
}