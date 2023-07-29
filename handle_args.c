#include "my_shell.h"

/**
 * handle_arguments - handle arguments
 * @line: string to break down
 * Return: void.
 */
int handle_arguments(char *line)
{
	char *command[1000], *token;
	int i = 0, status, builtin_status;

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		command[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	command[i] = NULL;
	while (i > 0)
	{
		builtin_status = handle_builtin(command[0], command);
		if (builtin_status != -1)
		{
			return (builtin_status);
		}
		status = execve_helper(command[0], command);
		if (status != 0)
		{
			perror("Command execution error");
			return (status);
		}
		i--;
	}
<<<<<<< HEAD

	return (0);
=======
	else if (_strcmp(command[0], "exit") == 0)
	{
		stat_ = exit_status(command[1]);
		return (0);
	}
	else if (_strcmp(command[0], "cd") == 0) 
	{
		return (handle_cd_command(command));
	}
	return (execve_helper(command[0], command));
>>>>>>> 1eee9c11927c4b308f76dec0ebf588aab8e9ac1c
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
<<<<<<< HEAD
		perror("path  error");
		return (-1);
=======
		perror("Path error");
		return (127);
>>>>>>> 1eee9c11927c4b308f76dec0ebf588aab8e9ac1c
	}

	if (execve(command_path, args, environ) == -1)
	{
<<<<<<< HEAD
		perror("Execve Error");
		return (-1);
=======
		perror("execve error");
		return (127);
>>>>>>> 1eee9c11927c4b308f76dec0ebf588aab8e9ac1c
	}
	return (0);
}
