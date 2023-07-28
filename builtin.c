#include "my_shell.h"

/**
 * _builtin - Handles env commands 
 * Return: 0
 */
int _builtin(void)
{
	if (!buf)
		return (0);
	if (!_strcmp(buf, "env"))
	{
		print_array(environ);
		return (0);
	}

	return (-1);
}
