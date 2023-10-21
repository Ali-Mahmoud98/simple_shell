#include "shell.h"

/**
 * get_history_file - Gets the history file.
 * @info: Parameter struct.
 *
 * This function constructs and returns an allocated string containing
 * the path to the history file based on the user's home directory.
 * If the 'HOME' environment variable is not found or if memory allocation
 * fails, it returns NULL.
 *
 * Return: An allocated string containing the history file or NULL on failure.
 */
char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (strlen(dir) + strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	strcpy(buf, dir);
	strcat(buf, "/");
	strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - Creates a file or appends to an existing file to store
 * history.
 * @info: The parameter struct.
 *
 * This function creates a history file or overwrites an existing one and
 * appends the command history entries from the 'info' structure to the file.
 * If the file creation and write operations are successful, it returns 1.
 * If any error occurs, such as failing to open the file or encountering issues
 * during writing, it returns -1.
 *
 * Return: 1 on success, -1 on failure.
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - Reads command history from a file.
 * @info: The parameter struct.
 *
 * This function reads command history entries from a file, populates the
 * history list in the 'info' structure, and updates the history count.
 * If the history file exists and is successfully read, it returns the history
 * count (histcount). If any error occurs during file operations or memory
 * allocation, it returns 0.
 *
 * Return: The history count on success, 0 on failure.
 */
int read_history(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - Adds an entry to a history linked list.
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: Buffer.
 * @linecount: The history line count (histcount).
 *
 * This function adds a new entry to the history linked list in the 'info'
 * structure, containing the provided buffer and line count. If the history
 * list does not exist, it creates it. The function always returns 0.
 *
 * Return: Always 0.
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	push_back(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
