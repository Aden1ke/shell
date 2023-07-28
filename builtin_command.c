#include "my_shell.h"
/**
 * handle_exit_command - Handles the exit command.
 * @args:  array of arguments.
 * Return: -1 to indicate that the shell should exit.
 */
int handle_exit_command(char **args)
{
	if (args[1] == NULL)
		return (0);
	else if (args[2] == NULL)
	{
		int status = _atoi(args[1]);
		if (status != -1)
		{
			return (status);
		}
		else
		{
			perror("Invalid argument for exit command");
			return (-1);
		}
	}
	else
	{
		perror("Usage: exit [status]");
		return (-1);
	}
	return (-1);
}

/**
 * handle_cd_command - Handles the cd command.
 * @args:  array of arguments.
 * Return: 0 on success, -1 on failure.
 */
int handle_cd_command(char **args)
{
	char *current_dir, *current_new_dir;

	if (args[1] == NULL || _strcmp(args[1], "~") == 0)
	{
		current_dir = get_env_value("HOME");
		if (current_dir == NULL)
		{
			perror("current environment not set");
			return (-1);
		} 
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		current_dir = get_env_value("OLDPWD");
		if (current_dir == NULL)
		{
			perror("OLDPWD environmentnot set");
            return (-1);
		}
		printf("%s\n", current_dir);
	}
	else
	{
		current_dir = args[1];
	}

	if (access(current_dir, F_OK) == -1)
	{
		perror("cd error");
		return (-1);
	}

	current_new_dir = getcwd(NULL, 0);
	if (current_new_dir != NULL) 
	{
		update_pwd(current_new_dir);
		putenv(_strcat("OLDPWD=", current_new_dir));
		free(current_new_dir);
	}
	else
	{
		perror("Failed to get current working directory");
	}

	if (chdir(current_dir) == -1)
	{
		perror("cd error");
		return (-1);
	}

	return (0);
}
