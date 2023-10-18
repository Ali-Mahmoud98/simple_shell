#include "shell.h"
/**
 * main - Entry point of the simple shell program.
 * @ac: The number of command-line arguments.
 * @av: An array containing the command-line arguments.
 *
 * Return: Always returns 0.
 */
int main(int ac, char **av)
{
	char *line = NULL;
	char **command;
	int status = 0, idx = 0;
	(void) ac;

	while (1)
	{
		write(1, "$ ", 2);
		line = read_line();
		if (line == NULL)
		{
			if (STDIN_FILENO)
				write(STDIN_FILENO, "\n", 1);
			return (status);
		}
		idx++;
		command = tokenizer(line);
		if (!command)
		continue;

		status = _execute(command, av, idx);
	}

}
