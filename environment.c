#include "shell.h"

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _myenv - Prints the current environment.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *
 * This function prints the current environment variables to the standard
 * output.
 * If the 'info' parameter is 'NULL', no action is taken.
 *
 */
int _env(info_t *info)
{
	print_list_str(info->env);
	return (1);
}

/**
 * _getenv - Gets the value of an environment variable.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @name: The name of the environment variable to retrieve.
 *
 * This function searches for an environment variable with the given
 * name in the provided environment list and returns its value.
 *
 * If the environment variable is found, its value is returned. If the variable
 * is not found or its value is an empty string, NULL is returned.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable or modify an existing one.
 * @info: Structure containing potential arguments. Used to maintain a constant
 *        function prototype.
 *
 * This function initializes a new environment variable or modifies an
 * existing one by setting its value. It expects exactly three arguments:
 * the command name, the variable name, and the value to assign.
 * If the arguments are not provided as expected, an error message is printed
 * to standard error, and the function returns 1 to indicate an error.
 * If the variable is set or modified successfully, the function returns 0.
 *
 * Return: 0 on success, 1 on error.
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable.
 * @info: Structure containing potential arguments. Used to maintain a constant
 *        function prototype.
 *
 * This function removes one or more environment variables specified as
 * arguments. If too few arguments are provided, an error message is printed
 * to standard error, and the function returns 1 to indicate an error.
 * If the variables are successfully unset, the function returns 0.
 *
 * Return: 0 on success, 1 on error.
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain a constant
 * function prototype.
 * Return: Always 0
 */
int _env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		push_back(&node, environ[i], 0);
	info->env = node;
	return (0);
}
