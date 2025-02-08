#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char cmd[] = "/bin/ls";

    char *av[] = {"ls", "-l", NULL};
    char *env[] = {NULL};
    printf("exe\n");

    if (execve(cmd, av, env) == -1)
        perror("error");
    printf("wrong\n");
}