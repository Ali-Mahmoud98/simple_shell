#include "shell.h"
/**
 * main - Entry point of the simple shell program.
 * @ac: The number of command-line arguments.
 * @av: An array containing the command-line arguments.
 *
 * Return: Always returns 0.
 */
int main(int ac __attribute__((unused)), char **av)
{
	ssize_t input_count;
	char *command = NULL;
	size_t command_size = 0;
	char **command_args;
	pid_t child_pid;
	int status, i;

	printf("cisfun$ ");
	while ((input_count = getline(&command, &command_size, stdin)) != EOF)
	{
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
			return (-1);
		}
		else if (child_pid == 0)
		{
			/*if (_strcmp(command, "env") == 0)
				_getenv();*/
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
	if (command != NULL)
	{
		free(command);
	}
	return (0);
}
