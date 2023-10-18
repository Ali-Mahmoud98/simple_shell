#include "shell.h"
/**
 * _getpath - Get the full path of a specified command.
 * @command: The command for which the full path is to be found.
 *
 * Return: A pointer to the full path of the command, or NULL if not found.
 */
char *_getpath(char *command)
{
	char *path_env, *full_cmd, *dir;
	struct stat st;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}

	path_env = _getenv("PATH");
	if (!path_env)
	return (NULL);

	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(strlen(dir) + strlen(command) + 2);
		if (full_cmd)
		{
			strcpy(full_cmd, dir);
			strcat(full_cmd, "/");
			strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd);
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
