#include "my_shell.h"
/**
 * handle_exit_command - Handles the exit command.
 * @args:  array of arguments.
 * Return: -1 to indicate that the shell should exit.
 */
int handle_exit_command(char **args)
{
	if (args[1] == NULL)
	{
		should_exit = true;
		return 0;
	}
	else if (args[2] == NULL)
	{
		int status = _atoi(args[1]);
		if (status != -1)
		{
			should_exit = true;
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
}

/**
 * handle_cd_command - Handles the cd command.
 * @args:  array of arguments.
 * Return: 0 on success, -1 on failure.
 */
int handle_cd_command(char **args)
{
	char *current_dir = NULL, *current_new_dir = NULL;

	if (args[1] == NULL || _strcmp(args[1], "~") == 0)
	{
		char *home_dir = get_env_value("HOME");
		if (home_dir == NULL)
		{
			perror("HOME environment variable not set");
			return (1);
		}
		if (chdir(home_dir) == -1)
		{
			perror("chdir error");
			return (1);
		}
		printf("Changed directory to: %s\n", home_dir);
		current_dir = home_dir;
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		char *old_pwd = get_env_value("OLDPWD");

		if (old_pwd == NULL)
		{
			perror("OLDPWD environment variable not set");
			return (1);
		}
		if (chdir(old_pwd) == -1)
		{
			perror("chdir error");
			return (1);
		}
		current_dir = old_pwd;
	}
	else
	{
		if (args[1][0] == '/')
			current_dir = args[1];
		else
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
		if (setenv("OLDPWD", current_new_dir, 1) == -1)
		{
			perror("Failed to update OLDPWD environment variable");
			exit(EXIT_FAILURE);
		}
		free(current_new_dir);
	}
	else

		perror("Failed to get current working directory");
	return (0);
}
