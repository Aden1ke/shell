#include "my_shell.h"
/**
 * handle_exit_command - Handles the exit command.
 * @args:  array of arguments.
 * Return: -1 to indicate that the shell should exit.
 */
int handle_exit_command(char **tokens)
{
	char *arg;
	int i, status;
	if (tokens[1] == NULL)
	{
		return (0);
	}
	else if (tokens[2] == NULL)
	{
		arg = tokens[1];
		for (i = 0; arg[i] != '\0'; i++)
		{
			if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '+')
			{
				fprintf(stderr, "hsh: exit: Illegal number: %s\n", arg);;
				return (-1);
			}
		}
		status = _atoi(arg);
		if (status != -1)
		{
			return (status);
		}
		else
		{
			fprintf(stderr, "hsh: exit: Illegal number: %s\n", arg);
			return -1;
		}
	}
	else
	{
		perror("Usage: exit [status]");
		return -1;
	}
}
