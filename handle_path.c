#include "shell.h"
/**
 * _getpath - Get the full path of a specified command.
 * @command: The command for which the full path is to be found.
 *
 * Return: A pointer to the full path of the command, or NULL if not found.
 */
char *_getpath(char *command)
{
	int i, k = 0;
	char *path = "/bin/";
	char *command_path;

	if ((strncmp(command, "/bin/", 5) != 0) &&
			(strncmp(command, "/usr/bin/", 9) != 0))
	{
		command_path = malloc(sizeof(char) * (5 + strlen(command) + 1));
		if (command_path == NULL)
			return (NULL);

		for (i = 0; path[i] != '\0'; i++)
			command_path[i] = path[i];

		for (k = 0; command[k] != '\0'; k++)
		{
			command_path[i] = command[k];
			i++;
		}
		command_path[i] = '\0';
		return (command_path);
	}
	return (command);
}
