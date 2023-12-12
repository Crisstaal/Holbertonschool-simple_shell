#include "shell.h"
#include <stdbool.h>
/**
 * get_delim - Checks if the character is a delimiter
 * @c: The character to check.
 * @delimiters: The string of delimiters
 *
 * This function iterates through the provided delimiters and checks
 * if the given character matches any of them. Returns true if the
 * character is a delimiter, and false otherwise
 * Used to identify and ignore repeated delimiters when splitting
 * a string into words
 *
 * Return: a pointer to an array of strings, or NULL on failure
*/
bool get_delim(char c, const char *delimiters)
{
	while (*delimiters != '\0')
	{
		if (c == *delimiters)
		{
			return (true);
		}
		delimiters++;
	}
	return (false);
}
/**
 * strtow - Splits a string into an array of words based on delimiters.
 * @str: The input string to be split.
 * @d: The delimiters used for word separation (default is space).
 *
 * This function takes a string and a set of delimiters
 * it splits the string into an array of words
 * The delimiters define where the string should be broken
 * into individual words. The function dynamically allocates memory
 * for the array of words and returns a pointer to it. Returns NULL on
 * failure or if the input string is empty
 *
 * Return: A pointer to an array of strings representing the words
 * NULL on failure.
 *
 *
 */

char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!get_delim(str[i], d) && (get_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (get_delim(str[i], d))
			i++;
		k = 0;
		while (!get_delim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
/**
 * main - Entry point of the program to test string splitting functions
 *
 * This function initializes variables, including an example input
 * string and delimiter, and then tests two string splitting functions:
 * `strtow` and `strtow2`. It prints the results of the `strtow` function
 * frees the allocated memory
 *
 * Return: EXIT_SUCCESS if the program completes successfully
 * EXIT_FAILURE otherwise.
 */

int main(void)
{
	int i, j;
	char input[] = "Hello Workd! This is a test.";
	char *delimeters = " ";

	char **result = strtow(input, delimeters);
	char **result2 = strtow2(input, ' ');

	if (result == NULL)
	{
		printf("Error in strtow function\n");
		return (EXIT_FAILURE);
	}
	printf("Result of strtow:\n");


	for (i = 0; result[i] != NULL; i++)
	{
		printf("%s\n", result[i]);
		free(result[i]);
	}
	free(result);

	if (result2 == NULL)
	{
		printf("Error in strtow2 function\n");
		return (EXIT_FAILURE);
	}
	printf("\nResult of strtow2: \n");

	for (j = 0; result2[i] != NULL; j++)
	{
		printf("%s\n", result2[i]);
		free(result2[i]);
	}
	free(result2);

	return (EXIT_SUCCESS);
}
