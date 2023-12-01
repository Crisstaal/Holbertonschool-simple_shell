#include <stdio.h>
#include <stdlib.h>

int main ()
{
	size_t buffsize = 32;
	char *buffer;

	buffer = malloc(sizeof(char) * buffsize);

	while (1)
	{
	printf("$ ");
	getline(&buffer, &buffsize, stdin);
	printf("%s\n", buffer);
	}
	return (0);
}
