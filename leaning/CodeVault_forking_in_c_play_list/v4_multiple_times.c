#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

// int main(void)
// {
//     int id1 = fork();
//     int id2 = fork();
//     if (id1 == 0)
//     {
//         if (id2 == 0)
//             printf("i dont have children i am y \n");
//         else
//             printf("i am process x\n");
//     }
//     else 
//     {
//         if (id2 == 0)
//             printf("i am process z\n");
//         else
//         printf("i am the parent process!\n");
//     }
//     while (wait(NULL) != -1 || errno != ECHILD)
//         printf("waited for a child to finish\n");
// }

int	main()
{
	int		id1 = fork();
	int		id2 = fork();

    while (wait(NULL) != -1 || errno != ECHILD)
        printf("waited for a child to finish\n");
	if (id1 == 0)
	{
		if (id2 == 0)
		{
			printf("grandchild\n");
		}
		else
		{
			printf("1st child of parent\n");
		}
	}
	else
	{
		if (id2 == 0)
		{
			printf("2nd child of parent\n");
		}
		else
		{
			printf("parent\n");
		}
	}
	return (0);
}