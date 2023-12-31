#include "my_shell.h"

/**
 * handle_arguments - handle arguments
 * @line: string to break down
 * Return: void.
 */
int handle_arguments(char *line)
{
	char *command[8096], *token;
	int i = 0;

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		command[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	command[i] = NULL;
	if (_strcmp(command[0], "env") == 0)
	{
		return (print_array(environ));
	}
	else if (_strcmp(command[0], "exit") == 0)
	{
		return (handle_exit_command(command));
	}
	else if (_strcmp(command[0], "cd") == 0)
	{
		return (builtin_cd(command));
	}
	else if (_strcmp(command[0], "setenv") == 0)
	{
		_setenv(command);
		return (0);
	}
	else if (_strcmp(command[0], "unsetenv") == 0)
	{
		_unsetenv(command);
		return (0);
	}
	else
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
		command_path = path(command_path);
	if (!command_path || access(command_path, X_OK) == -1)
	{
		prints(2, "%a: %b: %c: not found\n", shell, first, command);
		return (127);
	}

	if (execve(command_path, args, environ) == -1)
	{
		perror("execve error");
		return (0);
	}
	return (0);
}
