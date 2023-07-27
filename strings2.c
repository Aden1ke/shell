#include "my_shell.h"
/**
 * _strcpy - Copies the string pointed to by str,
 * with the terminating null byte, to the buffer.
 * @dest: Pointer to the destination of  string.
 * @str: Pointer to the str of the string.
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *str)
{
	size_t i;

	for (i = 0; str[i] != '\0'; i++)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * free_arr - frees memory allocated to an array
 * @arr: the array to be freed
 * Return: void
 */
void free_arr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);

	free(arr);
}
