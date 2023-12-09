#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	pid_t child_pid;
	int status;

	for (i = 1; 1 <= 5; i==)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("erroe:");
			return (1);
		}
	}
	if 
	
