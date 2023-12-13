#include "myshellk.h"

/**
 * find_env_key - find the environment variable key
 * @line: environment variable string
 * @ptr: input key
 * This function takes an environment variable string and a key, searches for
 * the key in the string, and returns a pointer to the corresponding value if
 * found. If the key is not found, the function returns NULL.
 * Return: pointer to the value or NULL if not found
 */
char *find_env_key(char *line, char *ptr)
{
	char *buf, *key, *value, *env;

	buf = _strdup(line);
	key = strtok(buf, "=");

	if (_strcmp(key, ptr) == 0)
	{
		value = strtok(NULL, "\n");
		env = _strdup(value);
		free(buf);
		return (env);
	}

	free(buf);
	return (NULL);
}

/**
 * _getenv - get the value of an environment variable
 * @ptr: input key
 *This function searches for the value of a specified environment variable
 * using the key.
 * Return: value or NULL if not found
 */
char *_getenv(char *ptr)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		char *env_value = find_env_key(environ[i], ptr);

		if (env_value != NULL)
			return (env_value);
	}

	return (NULL);
}


/**
 * is_absolute_path - check if the com is an absolute path
 * @com: input com
 * This function checks if the input command is an absolute path by using the
 * stat function.
 * Return: path or NULL
 */
char *is_absolute_path(char *com)
{
	struct stat st;

	if (stat(com, &st) == 0)
		return (strdup(com));

	return (NULL);
}

/**
 * search_in_path - search for the com in the PATH environment variable
 * @com: input com
 * This function searches for the input command in each directory specified
 * in the PATH environment variable.
 * Return: path or NULL
 */
char *search_in_path(char *com)
{
	char *path_env, *cmd, *road;
	struct stat st;

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	road = strtok(path_env, ":");
	while (road)
	{
		cmd = malloc(_strlen(road) + _strlen(com) + 2);
		if (cmd)
		{
			_strcpy(cmd, road);
			_strcat(cmd, "/");
			_strcat(cmd, com);
			if (stat(cmd, &st) == 0)
			{
				free(path_env);
				return (cmd);
			}
			free(cmd);
			road = strtok(NULL, ":");
		}
	}

	free(path_env);
	return (NULL);
}

/**
 * _getpath - get the path of input com
 * @com: input com
 * This function determines the path of the input command. If the command is an
 * absolute path, it returns a duplicated string of the command. Otherwise, it
 * searches for the command in the directories
 * variable and returns the full path if found; otherwise, it returns NULL.
 * Return: path or NULL
 */
char *_getpath(char *com)
{
	char *path;

	path = is_absolute_path(com);
	if (path != NULL)
		return (path);

	return (search_in_path(com));
}
