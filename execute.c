#include "shell.h"
/**
 * _execute - Execute a given command and wait for its completion.
 * @command: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing the program name and its arguments.
 * @idx: The index of the current command in the input.
 *
 * Return: The exit status of the executed process, or 127 on failure.
 */
int _execute(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t pid;
	int status;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		printerror(argv[0], command[0], idx);
		free2DArray(command);
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd);
			free2DArray(command);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free2DArray(command);
		free(full_cmd);
	}
	return (WEXITSTATUS(status));
}
