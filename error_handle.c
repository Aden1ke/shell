#include "my_shell.h"

/**
 * error_126 - An error message for permission denied.
 * @args: An array of arguments.
 * Return: The string.
 */
char *error_126(char **args)
{
	char *error, *incr_str;
	int len;

	incr_str = _itoa(incr);
	if (!incr_str)
		return (NULL);

	len = _strlen(name) + _strlen(incr_str) + _strlen(args[0]) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(incr_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, incr_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": Permission denied\n");

	free(incr_str);
	return (error);
}

/**
 * error_127 - Writes an error message for command not found.
 * @args: An array of arguments.
 * Return: The string.
 */
char *error_127(char **args)
{
	char *error, *incr_str;
	int len;

	incr_str = _itoa(incr);
	if (!incr_str)
		return (NULL);

	len = _strlen(name) + _strlen(incr_str) + _strlen(args[0]) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(incr_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, incr_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": not found\n");

	free(incr_str);
	return (error);
}

/**
 * handle_error - Writes a custom error message.
 * @args:  Arguments.
 * @err: The error.
 * Return: The value.
 */
int handle_error(char **args, int err)
{
	char *error;

	switch (err)
	{
	case 126:
		error = error_126(args);
		break;
	case 127:
		error = error_127(args);
		break;
	}
	write(STDERR_FILENO, error, _strlen(error));

	if (error)
		free(error);
	return (err);

}
