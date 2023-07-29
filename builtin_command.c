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
		return (0);
	}
	else if (args[2] == NULL)
	{
<<<<<<< HEAD
		int status = _atoi(args[1]);

=======
		int32_t status = _atoi(args[1]);
>>>>>>> 0575a4cc30b425aaed9771d72ed6a1fe4fe83026
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
}

/**
 * handle_cd_command - Handles the cd command.
 * @args:  array of arguments.
 * Return: 0 on success, -1 on failure.
 */
int handle_cd_command(char **args)
{
	char *current_dir = NULL;

	if (args[1] == NULL || _strcmp(args[1], "~") == 0)
	{
		return (handle_cd_to_home());
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		return (handle_cd_to_oldpwd());
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

	return (handle_change_directory(current_dir));
}

/**
 * handle_cd_to_home - Handle changing directory to HOME.
 * Return: 0 on success, 1 on failure.
 */
int handle_cd_to_home(void)
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
	update_pwd(home_dir);
	return (0);
}

/**
 * handle_cd_to_oldpwd - Handle changing directory to OLDPWD.
 * Return: 0 on success, 1 on failure.
 */
int handle_cd_to_oldpwd(void)
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
	printf("Changed directory to: %s\n", old_pwd);
	update_pwd(old_pwd);

	return (0);
}

/**
 * handle_change_directory - Handle changing directory to a specific path.
 * @path: The path to change directory to.
 * Return: 0 on success, -1 on failure.
 */
int handle_change_directory(char *path)
{
	if (chdir(path) == -1)
	{
		perror("chdir error");
		return (-1);
	}
	printf("Changed directory to: %s\n", path);
	update_pwd(path);
	return (0);
}
