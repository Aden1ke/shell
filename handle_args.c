#include "my_shell.h"

/**
 * handle_arguments - handle arguments
 * @line: string to break down
 * Return: void.
 */
int handle_arguments(char *line)
{
	char *command[1000], *token;
	int i = 0;

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		command[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	command[i] = NULL;
	if (_strcmp(command[0], "exit") == 0)
	{
		if (i == 1)
		{
			return (0); 
		}
		else if (i == 2)
		{
			int status = _atoi(command[1]);
			exit(status);
			return (status);
		}
		else
		{
			perror("Usage: exit [status]");
			return (-1);
		}
	}
	return (execve_helper(command[0], command));
}

/**
 * execve_helper - execute the command using execve
 * @command: the command to execute
 * @args: an array of arguments including the command itself
 * Return: void
 */
int execve_helper(char *command, char *args[])
{
	char *command_path = command;

	if (command_path[0] != '/' && command_path[0] != '.')
		command_path = locate_path(command_path);
	if (!command_path || access(command_path, X_OK) == -1)
	{
		perror("path error");
		return (-1);
	}

	if (execve(command_path, args, environ) == -1)
		{
			perror("Execve Error");
			return (-1);
		}
	return (0);
}
