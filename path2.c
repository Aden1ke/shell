#include "my_shell.h"

/**
 * dup_str - allocate a string duplicate
 * @str: string
 * Return: string duplicate
*/
char *dup_str(char *str)
{
	char *ptr, *ptr_char;
	size_t len;

	if (!str)
		return (NULL);

	for (len = 0; str[len]; len++)
		;

	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);

	ptr_char = ptr;

	while (*str)
	{
		*ptr_char = *str;
		str++;
		ptr_char++;
	}
	*ptr_char = '\0';
	return (ptr);
}

/**
 * path - search through the directories to execute command
 * Return: absolute path
 */
char *path(char *command)
{
	int i = 0;
	char *path_val = get_env("PATH");
	char **path_dir, *abs_path;

	if (access(command, F_OK) == 0)
		return (dup_str(command));

	if (!path_val)
		return (NULL);

	path_dir = str_tok(path_val, ':');

	for (i = 0; path_dir[i]; i++)
	{
		abs_path = malloc(1024);
		_strcpy(abs_path, path_dir[i]);
		_strcat(abs_path, "/");
		_strcat(abs_path, command);

		if (access(abs_path, F_OK) == 0)
		{
			free_array(path_dir);
			return (abs_path);
		}
		free(abs_path);
	}
	free_array(path_dir);

	return (NULL);
}

/**
 * str_tok - converts a string to an array
 * @str: the string
 * @delim: the delimiter
 * Return: array of the strings
 */
char **str_tok(char *str, char delim)
{
	int i = 0, j = 0, k = 0;
	int len = _strlen(str);
	char **array = (char **)malloc(sizeof(char *) * (len + 1));
	char *buf = (char *)malloc(sizeof(char) * (len + 1));


	for (; i < len + 1; i++)
	{
		if (str[i] != delim && str[i] != '\0')
		{
			buf[k] = str[i];
			k++;
		}
		else
		{
			if (k > 0)
			{
				buf[k] = '\0';
				array[j] = malloc(sizeof(char) * (k + 1));
				_strcpy(array[j], buf);
				j++;
				k = 0;
			}
		}
	}

	array[j] = NULL;
	free(buf);

	return (array);
}
