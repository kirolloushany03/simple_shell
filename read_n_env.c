#include "myshellk.h"

/**
 * read_com - read input com
 *This function reads the user input for a command line. If in interactive
 * mode, it prompts the user with "#Kiro$ ".
 * Return: com
*/

char *read_com(void)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t read_com;

	if (isatty(STDIN_FILENO))
		_putchar("#Kiro$ ");
	read_com = getline(&line, &line_size, stdin);
	if (read_com == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
/**
 * print_env - function to not print $
* This function prints the environment variables to standard output. It
 * iterates through the global 'environ' array and prints each variable
 * followed by a newline character.
 * Return: output
*/

void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_putchar(environ[i]);
		_putchar("\n");
	}
}
/**
 * _putchar - print the input string
 * @c: input string
 * This function writes the input string to standard output using the
 * write function. It is used to print strings in the custom shell.
 * Return: string
 */

void _putchar(const char *c)
{
	write(STDOUT_FILENO, c, _strlen(c));
}
