#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

// close(fd[0][0]);
// close(fd[0][1]);
// close(fd[1][0]);
// close(fd[1][1]);
// close(fd[2][0]);
// close(fd[2][1]);

int main(int ac, char **av)
{
   int fd[3][2];
   int i;
   for (i = 0; i < 3; i++)
   {
        if (pipe(fd[i]) < 0)
            return 1;
   }
    int pid1 = fork();
    if (pid1 == -1)
        return 2;
    if (pid1 == 0)
    {
        // child process 1
        close(fd[0][1]);
        close(fd[1][0]);
        close(fd[2][0]);
        close(fd[2][1]);
        int x;
        read(fd[0][0], &x, sizeof(int));
        x += 5;
        write(fd[1][1], &x, sizeof(int));
        close(fd[1][1]);
        close(fd[0][0]);
        return 0;
    }
    int pid2 = fork();
    if (pid2 == 0)
    {
        close(fd[0][0]);
        close(fd[0][1]);
        close(fd[1][1]);
        close(fd[2][0]);
        int x;
        read(fd[1][0], &x, sizeof(int));
        x += 5;
        write(fd[2][1], &x, sizeof(int));
        close(fd[1][0]);
        close(fd[2][1]);
        return (0);
    }
    close(fd[0][0]);
    close(fd[1][0]);
    close(fd[1][1]);
    close(fd[2][1]);
    int x;
    printf ("put an input i will add to it five from the child1 and anther five from child 2:    ");
    scanf("%d", &x);
    write (fd[0][1], &x, sizeof(int));
    printf ("my input is: %d\n", x);
    read(fd[2][0], &x, sizeof(int));
    printf("my output is: %d\n", x);
    close(fd[0][1]);
    close(fd[2][0]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}