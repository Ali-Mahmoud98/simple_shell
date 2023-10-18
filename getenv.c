#include "shell.h"
/**
 * _getenv - Get the value of a specified environment variable.
 * @var: The name of the environment variable.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if not found.
 */
char *_getenv(char *var)
{
	char *tmp, *value, *key, *env;
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
	free(tmp);
	}
	return (NULL);
}
