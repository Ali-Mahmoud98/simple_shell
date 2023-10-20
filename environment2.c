#include "shell.h"

/**
 * get_environ - Returns a copy of the 'environ' environment as a string array.
 * @info: Structure containing potential arguments. Used to maintain a constant
 * function prototype.
 *
 * This function returns a pointer to a string array containing a copy of the
 * 'environ' environment. If the environment has been modified ('env_changed'
 * is set), it regenerates the string array before returning it.
 *
 * Return: A pointer to the string array. Always 0 to indicate success.
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Remove an environment variable.
 * @info: Structure containing potential arguments. Used to maintain a
 * constant function prototype.
 * @var: The string representing the environment variable to remove.
 *
 * This function removes the specified environment variable from the
 * environment linked list. If the variable is found and removed, the
 * function returns 1.
 * If the variable is not found, the function returns 0.
 *
 * Return: 1 on deletion, 0 when the variable is not found.
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable or modify an existing one.
 * @info: Structure containing potential arguments. Used to maintain a constant
 * function prototype.
 * @var: The string representing the environment variable property.
 * @value: The string representing the environment variable value.
 * Return: Always 0.
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
