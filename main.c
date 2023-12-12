#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024

void executeCommand(char *command)
{
	system(command);
}

int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		printf("MyShell$ ");

		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			printf("Error reading input\n");
			exit(EXIT_FAILURE);
		}

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			printf("Exiting MyShell\n");

			break;
		}

		executeCommand(input);
	}

	return (0);
}
