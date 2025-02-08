#include <stdio.h>

int	main(void)
{
	int i;

	do
	{
		printf("enter\n");
		scanf("%d", &i);
	} while (i != 0);
		printf("%d\n", i);
}