#include "my_shell.h"
/**
 * my_getline - my personal getline.
 * @buffer: string inputed.
 * @n: length of string.
 * @stream: file descriptor.
 * Return: 0n success 1.
 */
ssize_t my_getline(char **buffer, size_t *n, FILE *stream)
{
	initialize_buffer(buffer, n);
	return (read_from_buffer(buffer, n, stream));
}
/**
 * initialize_buffer - my personal getline.
 * @buffer: string inputed.
 * @n: length of string.
 * Return: 0n success 1.
 */
void initialize_buffer(char **buffer, size_t *n)
{
	if (buffer == NULL || n == NULL)
		return;

	if (*buffer == NULL || *n == 0)
	{
		*n = 8096;
		*buffer = _calloc(*n, sizeof(char));
		if (*buffer == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * read_from_buffer - my personal getline.
 * @buffer: string inputed.
 * @n: length of string.
 * @stream: file descriptor.
 * Return: 0n success 1.
 */
ssize_t read_from_buffer(char **buffer, size_t *n, FILE *stream)
{
	static char read_buffer[8096];
	static size_t buffer_position;
	static ssize_t bytes_in_buffer;
	size_t i = 0;
	char result;
	int newline_found = 0;

	while (!newline_found)
	{
		if ((ssize_t)buffer_position >= bytes_in_buffer)
		{
			bytes_in_buffer = read(fileno(stream), read_buffer, 8096);
			buffer_position = 0;
			if (bytes_in_buffer <= 0)
				break;
		}
		result = read_buffer[buffer_position++];
		(*buffer)[i++] = result;
		if (result == '\n')
			newline_found = 1;
		if (i >= *n - 1)
		{
			*n *= 2;
			*buffer = realloc(*buffer, *n * sizeof(char));
			if (*buffer == NULL)
			{
				exit(EXIT_FAILURE);
			}
		}
	}

	if (i == 0 && bytes_in_buffer <= 0)
	{
		return (-1);
	}

	(*buffer)[i] = '\0';
	return ((ssize_t)i);
}
