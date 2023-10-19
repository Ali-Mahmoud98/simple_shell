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
	char *line = NULL;
	char **command;
	int status = 0, idx = 0;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;

		command = tokenizer(line);
		if (!command)
			continue;
		if (is_builtin(command[0]))
			handle_builtin(command, av, &status, idx);
		else
			status = _execute(command, av, idx);
	}
	if (command != NULL)
	{
		free(command);
	}
	return (0);
}
