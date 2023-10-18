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

	printf("cisfun$ ");
	while ((input_count = getline(&command, &command_size, stdin)) != EOF)
	{
		if (input_count == 1 && command[0] == '\n')
		{
			printf("cisfun$");
		} else
		{
			execute(input_count, av, command);
		}
	}
	if (command != NULL)
	{
		free(command);
	}
	return (0);
}
