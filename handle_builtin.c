#include "shell.h"

/**
 * is_builtin - Check if a command is a built-in shell command.
 * @command: The command to be checked.
 *
 * Return: 1 if the command is built-in, 0 otherwise.
 */
int is_builtin(char *command)
{
	char *builtins[] = {"exit", "env", "setenv", "cd", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (strcmp(builtins[i], command) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * handle_builtin - Handle execution of built-in shell commands.
 * @command: The command to be executed.
 * @argv: The array of command-line arguments.
 * @status: The exit status of the shell.
 * @idx: The index number.
 */
void handle_builtin(char **command, char **argv, int *status, int idx)
{
	if (strcmp(command[0], "exit") == 0)
		exit_shell(command, argv, status, idx);
	else if (strcmp(command[0], "env") == 0)
		print_env(command, status);
}

/**
 * exit_shell - Handle the exit shell command.
 * @command: The command and its arguments.
 * @argv: The array of command-line arguments.
 * @status: The exit status of the shell.
 * @idx: The index number.
 */
void exit_shell(char **command, char **argv, int *status, int idx)
{
	int exit_value = (*status);
	char *index, mssg[] = ": exit:illegal number: ";

	index = _itoa(idx);
	if (command[1])
	{
		if (is_positive_number(command[1]))
			exit_value = atoi(command[1]);
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, strlen(index));
			write(STDERR_FILENO, mssg, strlen(mssg));
			write(STDERR_FILENO, command[1], strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free2DArray(command);
			(*status) = 2;
			return;
		}
	}
	free2DArray(command);
	exit(exit_value);
}

/**
 * print_env - Print environment variables to standard output.
 * @command: The command and its arguments.
 * @status: The exit status of the shell.
 */
void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(0, environ[i], strlen(environ[i]));
		write(0, "\n", 1);
	}
	free2DArray(command);
	(*status) = 0;
}
