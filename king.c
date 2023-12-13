#include "myshellk.h"

/**
 * main - main function
 * @argc: argument c
 * @argv: argument v
 * The main function serves as the entry point for the custom shell program. It
 * initializes variables, enters an infinite loop to
 * user commands, and handles built-in commands such as
 * prompts the user for input, tokenizes the input comm
 * corresponding command using the ex_com function.
* Return: void
*/

int main(int argc, char **argv)
{
	char *line = NULL;
	char **com;
	int status = 0, ix = 0;
	(void) argc;

	while (1)
	{
		line = read_com();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO)) /*to not print $*/
				_putchar("\n");
			return (status);
		}
		ix++;
		com = tokenizer(line);
		if (!com)
			continue;
		if (_strcmp(com[0], "exit") == 0)
		{
			freearray(com);
			return (status);
		}
		else if (_strcmp(com[0], "env") == 0)
		{
			print_env();
			freearray(com);
		}
		else
			status = ex_com(com, argv, ix);
	}
}
