#include "shell.h"
/**
 * execute - Entry point of the simple shell program.
 * @input_count: length of entered command.
 * @av: An array containing the command-line arguments.
 * @command: command
 *
 * Return: Always returns 0.
 */
void execute(ssize_t input_count, char **av, char *command)
{
	char **command_args;
	pid_t child_pid;
	int status, i;

	if (command[input_count - 1] == '\n')
		command[input_count - 1] = '\0';
	if (strcmp(command, "exit") == 0)
		exit(98);
	command = _getpath(command);
	command_args = tokenizer(command);
	child_pid = fork();
	if (child_pid == -1)
	{
		printf("fork ERROR\n");
		exit(-1);
	}
	else if (child_pid == 0)
	{
		i = execve(command_args[0], command_args, environ);
		if (i == -1)
		{
			printf("%s: No such file or directory\n", av[0]);
			_exit(99);
		}
	}
	else
		wait_print(&status, "cisfun$");
	if (command_args != NULL)
	{
		free2DArray(command_args);
	}
}
