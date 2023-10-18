#include "shell.h"
/**
 * tokenizer - Tokenize a string into an array of strings.
 * @line: The input string to be tokenized.
 *
 * Return: An array of tokenized strings, or NULL on failure.
 */
char **tokenizer(char *line)
{
	char **command = NULL;
	char *token = NULL, *line_cpy = NULL;
	int ac = 0, i = 0;

	if (!line)
		return (NULL);

	line_cpy = _strdup(line);

	token = strtok(line_cpy, DELIM);
	while (token)
	{
		ac++;
		token = strtok(NULL, DELIM);
	}
	free(line_cpy), line_cpy = NULL;

	command = malloc(sizeof(char *) * (ac + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	command[i] = NULL;
	free(line), line =  NULL;
	return (command);
}
