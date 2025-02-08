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
    int pid1 = fork();
    if (pid1 == -1)
        return 2;
    if (pid1 == 0)
    {
        // child process (ping)
        // fd[1] -> write end of the pipe /// fd[0] ->read nd of the pipe
        dup2(fd[1], STDOUT_FILENO);
        close (fd[0]);
        close(fd[1]);
        execlp("ping", "ping", "-c", "4", "google.com", NULL);
    }
    // every thing that we will write will be just execute by the parents because 
    // (execpl that we use in the child process replase the child process with the child proces)
    // so we dont need un if condtion
    int pid2 = fork();
    if (pid2 == -1)
        return 3;
    if (pid2 == 0)
    {
        dup2(fd[0], STDIN_FILENO);
        close (fd[0]);
        close(fd[1]);
        execlp("grep", "grep", "ms", NULL);
    }
    close (fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return (0);
}