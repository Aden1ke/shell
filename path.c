#include "my_shell.h"
/**
 * get_env - Gets the env from the path.
 * @var: The name of the env variable.
 * Return: If no env variable - NULL.
 * Otherwise - a pointer to the env variable.
 */
char **get_env(const char *var)
{
	int start, len;

	len = _strlen(var);
	for (start = 0; env[start]; start++)
	{
		if (_strncmp(var, env[start], len) == 0)
			return (&env[start]);
	}

	return (NULL);
}

/**
 * fill_path - Copies path but also replace
 * colons (:) with current working directory.
 * @path: The colon-separated list of directories.
 * Return: A copy of path with any  colons replace
 * with the current working directory.
 */
char *fill_path(char *path)
{
	int i, len = 0;
	char *path_copy, *pwd;

	pwd = *(get_env("PWD")) + 4;
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (path[i + 1] == ':' || i == 0 || path[i + 1] == '\0')
				len += _strlen(pwd) + 1;
			else
				len++;
		}
		else
			len++;
	}
	path_copy = malloc(sizeof(char) * (len + 1));
	if (!path_copy)
		return (NULL);
	path_copy[0] = '\0';
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (i == 0)
			{
				_strcat(path_copy, pwd);
				_strcat(path_copy, ":");
			}
			else if (path[i + 1] == ':' || path[i + 1] == '\0')
			{
				_strcat(path_copy, ":");
				_strcat(path_copy, pwd);
			}
			else
				_strcat(path_copy, ":");
		}
		else
		{
			_strncat(path_copy, &path[i], 1);
		}
	}
	return (path_copy);
}


/**
 * get_path - Tokenizes a colon-separated list of
 * directories into a linked list.
 * @path: The colon-separated list of directories.
 * Return: A pointer to the linked list.
 */
list_t *get_path(char *path)
{
	int start;
	char **dirs, *path_copy;
	list_t *head = NULL;

	path_copy = fill_path(path);
	if (!path_copy)
		return (NULL);
	dirs = strtok(path_copy, ":");
	free(path_copy);
	if (!dirs)
		return (NULL);

	for (start = 0; dirs[start]; start++)
	{
		if (node_end(&head, dirs[start]) == NULL)
		{
			free_list(head);
			free(dirs);
			return (NULL);
		}
	}
	free(dirs);

	return (head);
}

/**
 * Locate_path - Locates a command in the PATH.
 * @com: The command to locate.
 * Return: If error occurs and com is not located
 * NULL. Otherwisethe full pathname of the com.
 */
char *locate_path(char *com)
{
	char **path, *temp;
	list_t *dirs, *head;
	struct stat st;

	path = get_env("PATH");
	if (!path || !(*path))
		return (NULL);

	dirs = get_path(*path + 5);
	head = dirs;

	while (dirs)
	{
		temp = malloc(_strlen(dirs->dir) + _strlen(command) + 2);
		if (!temp)
			return (NULL);

		_strcpy(temp, dirs->dir);
		_strcat(temp, "/");
		_strcat(temp, com);

		if (stat(temp, &st) == 0)
		{
			free_list(head);
			return (temp);
		}

		dirs = dirs->next;
		free(temp);
	}

	free_list(head);

	return (NULL);
}
