#include <stdio.h>
#include <stdlib.h>

int main (int ac, char **av)
{
	int num = 0;
	size_t buffsize = 32, character;
	char *buffer;

	buffer = malloc(sizeof(char) * buffsize);

	while (num < ac)
	{
		printf("%s\n", av[num]);
		num++;
	}

	printf("$ ");
	character = getline(&buffer, &buffsize, stdin);
	printf("%ld: ", character);
	printf("%s\n", buffer);
	return (0);
}
