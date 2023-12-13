#include <stddef.h>
#include <string.h>
#include <stdlib.h>

/**
 * tokenizer - Tokenizes the input com line.
 * @line: Input com line to be tokenized.
 *
 * Return: An array of tokens if successful, NULL otherwise.
 *
 * This function parses and tokenizes an input com line, breaking it into
 * individual tokens based on whitespace characters (space, tab, and newline).
 * It dynamically allocates memory to create an array to store the tokens and
 * ensures proper memory cleanup in case of allocation failures. The tokenized
 * array is terminated with a NULL pointer to signify the end of the array.
 */
char **tokenizer(char *line)
{
	char *buf = NULL;
	char *token = NULL;
	char **array = NULL;
	int i;

	if (!line)
		return (NULL);

	buf = strdup(line);
	token = strtok(buf, " \t\n");
	if (token == NULL)
	{
		free(line);
		free(buf);
		return (NULL);
	}

	for (i = 0; token; i++)
		token = strtok(NULL, " \t\n");

	free(buf);
	array = malloc(sizeof(char *) * (i + 1));

	if (!array)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, " \t\n");
	for (i = 0; token; i++)
	{
		array[i] = strdup(token);
		token = strtok(NULL, " \t\n");
	}

	free(line);
	array[i] = NULL;
	return (array);
}
