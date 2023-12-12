#include "shell.h"
#include <stdbool.h>
/**
 * interactive - checks if the shell is running in interactive mode
 * @info: A pointer to the info_t struct that holds relevant information
 *
 * This function determines if the shell is running in interactive mode
 * by checking whether the standard input is connected to a terminal and
 * if the read file descriptor is less than or equal to 2
 * Return: 1 if the shell is in interactive mode, and 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
bool is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * main - Entry point of the simple shell program in interactive mode.
 *
 * Initializes the `info` structure, checks if the shell is in
 * interactive mode, prompts the user for a command in interactive mode
 * Then processes the entered command, handling the newline character
 * if present. The function distinguishes
 * between interactive and non-interactive modes
 *
 * Return: Always returns 0
 */



int main(void)
{
	info_t info;
	char user_input[100];

	if (interactive(&info))
	{
		printf("Interactive mode\n");

	printf("Enter a command: ");
	fgets(user_input, sizeof(user_input), stdin);

	if (user_input[strlen(user_input) - 1] == '\n')
	{
		user_input[strlen(user_input) - 1] = '\0';

	printf("Processing command: %s\n", user_input);
	}
	else
		printf("Non-interactive mode\n");
	}
	return (0);
}
