#include "shell.h"

/**
 * get_history_file - gets the details of the history file
 * @info: parameter of the struct
 *
 * Return: the string containing the history file
 */

char *get_history_file(info_t *info)
{
	char *buff, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, dir);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * write_history - creates a history file and write on it if empty
 * @info: the parameter struct
 *
 * Return: 1 on success, otherwise -1
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
 * read_history - reads from the history file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int a, l = 0, linecount = 0;
	ssize_t fdata, rdlen, fsize = 0;
	struct stat st;
	char *buff = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fdata = open(filename, O_RDONLY);
	free(filename);
	if (fdata == -1)
		return (0);
	if (!fstat(fdata, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (fsize + 1));
	if (!buff)
		return (0);
	rdlen = read(fdata, buff, fsize);
	buff[fsize] = 0;
	if (rdlen <= 0)
		return (free(buff), 0);
	close(fdata);
	for (a = 0; a < fsize; a++)
		if (buff[a] == '\n')
		{
			buff[a] = 0;
			build_history_list(info, buff + l, linecount++);
			l = a + 1;
		}
	if (l != a)
		build_history_list(info, buff + l, linecount++);
	free(buff);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - adds data to history linked list
 * @info: container for the actual argument
 * @buff: buffer variable
 * @linecount: the history linecount and histcount
 *
 * Return: 0 Always
 */
int build_history_list(info_t *info, char *buff, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buff, linecount);

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

