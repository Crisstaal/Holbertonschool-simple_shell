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

	if (feof(stdin) || ferror(stdin))
	{
		printf("Exiting the shell ...\n");
			break;
	}
	
	printf("%s\n", buffer);
	}


	free(buffer);
	return (0);
}
