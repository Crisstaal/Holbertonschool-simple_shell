#include "shell.h"
#include <stdlib.h>
/**
 *  strtok - splits string
 *  @str: input string
 *  @delim: delimeter
 *  Return: pointer to an array or NULL
 */

char **strtok(char *str, char *delim)
{
	int a, b, c, d, num = 0;
	char **r;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (delim != NULL)
		delim = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!getdelim(str[a], delim) && (getdelim(str[a + 1], delim) || !str[a + 1]))
			num++;
	if (num == 0)
		return (NULL);
	r = malloc ((1 + num) * sizeof(char *));
	if (r == NULL)
		return (NULL);
	for (a = 0; b = 0; b < num; b++)
	{
		while (getdelim(str[a], delim))
			a++;
		c = 0;
		while (!getdelim(str[a + c], delim) && str[a + c])
			c++;
		r[b] = malloc((c + 1) * sizeof(char));
		if (!r[b])
		{
			for (c = 0; c < b; c++)
				free(r[c]);
			free(r);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			r[b][d] = str[a++];
		r[b][d] = 0;
	}
	r[b] = NULL;
	return(r);
}
/**
 * strtok2 - splits a string into words
 * @str: string
 * @delim: delimeter
 * Return: a pointer to an array
 */

char **strtok2(char *str, char delim)
{
	int a, b, c, d, num = 0;
	char **r;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != delim && str[a +1] == delim) || (str[a] != delim && !str[a + 1]) || str[a + 1] == delim)
			num++;
	if (num == 0)
		return (NULL);
	r = malloc((1 + num) * sizeof(char *));
	if(r == NULL)
		return (NULL);
	for (a = 0; b = 0; b < num; b++)
	{
		while (str[a] == delim && str[a])
			a++;
		c = 0;
		while (str[a + c] != delim && str[a + c] && [a + c] != delim)
			c++;
		r[b] = malloc((c + 1) * sizeof(char));
		if (!r[b])
		{
			for (c = 0; c < b; c++)
				free(r[c]);
			free(r);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			r[b][d] = str[a++];
		r[b][d] = 0;
	}
	r[b] = NULL;
	return (r);
}
