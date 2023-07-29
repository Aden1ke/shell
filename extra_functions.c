#include "my_shell.h"
/**
 * _atoi - a function that convert a string to an integer.
 * @s: pointer to a string.
 * Return: Always 0.
 */
int _atoi(const char *s)
{
	int sign = 1;
	unsigned int num = 0;
	int digit_seen = 0;

	for (; *s != '\0'; s++)
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			num = (num * 10) + (*s - '0');
			digit_seen = 1;
		}
		else
			return (-1);
	}
	if (!digit_seen)
	{
		return (-1);
	}
	return (num * sign);
}
/**
 * _islower - Write a function that checks for lowercase character.
 * @c:value to be checked.
 * Return: Always 0.
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
		return (0);
}
/**
 * free_array - handle arguments
 * @array: string to break down
 * Return: void.
 */
void free_array(char **array)
{
	int i;

	if (array == NULL)
	{
		return;
	}

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}

	free(array);
}
/**
 * normalize_path - normlize path.
 * @path:  array of arguments.
 * Return: 0 on success, -1 on failure.
 */
void normalize_path(char *path) 
{
	int i, j;
	int len = _strlen(path);
	int is_slash = 0;

	j = 0;
	for (i = 0; i < len; i++)
	{
		if (path[i] == '/')
		{
			if (!is_slash)
			{
				path[j] = path[i];
				j++;
			}
			is_slash = 1;
		}
		else
		{
			path[j] = path[i];
			j++;
			is_slash = 0;
		}
	}
	path[j] = '\0';
}
