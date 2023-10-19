#include "shell.h"
/**
 * _strdup - Create a duplicate of a string.
 * @str: The string to be duplicated.
 *
 * Return: A pointer to the duplicated string, or NULL on failure.
 */
char *_strdup(char *str)
{
	char *dest = NULL;

	if (!str)
		return (NULL);

	dest = malloc(sizeof(char) * (strlen(str) + 1));
	if (!dest)
	{
		return (NULL);
	}
	strcpy(dest, str);
	return (dest);
}
