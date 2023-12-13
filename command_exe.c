#include "myshellk.h"

/**
 * printerror - print an error massage
 * @name: input name
 * @cmd: input com
 * @idx: input i_num
 * * This function prints an error message to standard error output
 * a specified command was not found.
 * the program, the index, and the
 * Return:No explicit return value;
*/

void printerror(char *name, char *cmd, int idx)
{
	char *i_num, msg[] = ": not found\n";

	i_num = _itoa(idx);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i_num, _strlen(i_num));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(i_num);
}




/**
 * execute_com - execute the com
 * @cmd: com path
 * @com: input com
 * This function forks a new process
 * execve system call. If the execution fails, it prints an error message and
 * exits the child process with status code 127.
 * Return: The exit status of the executed command
 */
int execute_com(char *cmd, char **com)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(cmd, com, environ) == -1)
		{
			free(cmd);
			freearray(com);
			exit(127);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		freearray(com);
		free(cmd);
	}

	return (WEXITSTATUS(status));
}

/**
 * ex_com - function to execute the com
 * @com: input com
 * @argv: input argv
 * @idx: input i_num
 * This function determines the path
 * and returns the exit status.
 * Return: exit status
 */
int ex_com(char **com, char **argv, int idx)
{
	char *cmd = get_com_path(com, argv, idx);
	int exit_status;

	if (!cmd)
		return (127);

	exit_status = execute_com(cmd, com);
	return (exit_status);
}
