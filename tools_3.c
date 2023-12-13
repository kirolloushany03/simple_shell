#include "myshellk.h"

/**
 * reverse_str - Reverses a string.
 * @str: Input string to be reversed.
 * @len: Length of the string.
 *
 * Return: Reversed string.
 *
 * This function takes an input string and its length, then reverses the string
 * in place using a two-pointer swapping technique. The reversed string is
 * modified directly in the input parameter.
 */
void reverse_str(char *str, int len)
{
	char tmp;
	int start;
	int end = len - 1;

	for (start = 0; start < end; start++, end--)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
	}
}

/**
 * _itoa - Converts an integer to a string.
 * @n: Input integer to be converted.
 *
 * Return: String representation of the input integer.
 *
 * This function converts an integer to its corres
 * It uses a temporary buffer for the conversion, and the resulting string is
 * dynamically allocated using _strdup. The caller is responsible for freeing
 * the allocated memory.
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_str(buffer, i);
	return (_strdup(buffer));
}

/**
 * freearray - Frees a dynamically allocated array of strings.
 * @array: Input array of strings to be freed.
 *
 * This function frees the memory allocated for each string in the input array
 * and then frees the memory for the array itself. It ensures proper cleanup
 * even if the input array is already NULL.
 */
void freearray(char **array)
{
	int i;

	if (!array)
		return;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}

	free(array);
}

/**
 * get_com_path - get the path of the input com
 * @com: input com
 * @argv: input argv
 * @idx: input ix
 * Return: com path or NULL
 */
char *get_com_path(char **com, char **argv, int idx)
{
	char *cmd = _getpath(com[0]);

	if (!cmd)
	{
		printerror(argv[0], com[0], idx);
		freearray(com);
		return (NULL);
	}

	return (cmd);
}
