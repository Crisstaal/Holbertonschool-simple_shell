#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i;

	printf("argv content is argv[]\n");

	while (av != NULL)
	{
		printf("argv[%d] = %s\n", i, av[i]);
		sum += atoi(av[i]); 
	}
	printf("sum is %d\n", sum);

	return (0);
}
