#include "my_shell.h"
/**
 * my_getline - my personal getline.
 * @argc: number of arguments.
 * @argv: arguments inputed.
 * Return: 0n success 1.
 */
ssize_t my_getline(char **buffer, size_t *n, FILE *stream)
{
	size_t i = 0;
	char *result;
	if (buffer == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	if (*buffer == NULL || *n == 0)
	{
		*n = 128; 
		*buffer = malloc(*n * sizeof(char));
		if (*buffer == NULL)
		{
			return (-1);
		}
	}
	while ((result = fgets(*buffer + i, *n - i, stream)) != NULL)
	{
		size_t len = strlen(*buffer + i);
		i += len;
		if ((*buffer)[i - 1] == '\n')
		{
			(*buffer)[i - 1] = '\0';
			break;
		}
		if (i >= *n - 1)
		{
			*n *= 2;
			*buffer = realloc(*buffer, *n * sizeof(char));
			if (*buffer == NULL)
			{
				return (-1);
			}
		}
	}
		if (i == 0 && result == NULL)
		{
			return (-1);
		}
		return ((ssize_t)i);
}
