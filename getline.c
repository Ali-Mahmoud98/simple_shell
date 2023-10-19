#include "shell.h"
/**
 * read_line - Read a line of input from the standard input.
 *
 * Return: A pointer to the input line, or NULL on error or EOF.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
