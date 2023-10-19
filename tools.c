#include "shell.h"
/**
 * _itoa - Convert an integer to a string.
 * @num: The integer to be converted.
 *
 * Return: A pointer to the string representation of the integer,
 * or NULL on failure.
 */
char *_itoa(int num)
{
	int i = 0;
	char buf[20];

	if (num == 0)
	{
		buf[i++] = '0';
		buf[i] = '\0';
	}
	else
	{
		while (num > 0)
		{
			buf[i++] = (num % 10) + '0';
			num /= 10;
		}
		buf[i] = '\0';
		reverse_string(buf, i);
		return (_strdup(buf));
	}
	return (_strdup(buf));
}

/**
 * reverse_string - Reverse a string.
 * @str: The string to be reversed.
 * @len: The length of the string.
 */

void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

/**
 * printerror - Print an error message to the standard error output.
 * @name: The program name.
 * @cmd: The command causing the error.
 * @idx: The index number.
 */
void printerror(char *name, char *cmd, int idx)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);
	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, strlen(index));
	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, mssg, strlen(mssg));
	free(index);
}

/**
 * is_positive_number - Check if a string represents a positive number.
 * @str: The string to be checked.
 *
 * Return: 1 if 'str' is a positive number, 0 otherwise.
 */
int is_positive_number(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
