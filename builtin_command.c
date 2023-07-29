#include "my_shell.h"
/**
 * handle_exit_command - Handles the exit command.
 * @args:  array of arguments.
 * Return: -1 to indicate that the shell should exit.
 */
int handle_exit_command(char **tokens)
{
	int i;

	if (tokens[1] != NULL)
	{ 
		for (i = 0; tokens[1][i]; i++)
		{
			if ((tokens[1][i] < '0' || tokens[1][i] > '9') && tokens[1][i] != '+')
			{
				errno = 2;
				return (2);
			}
		}
		errno = _atoi(tokens[1]);
	}
	free_array(tokens);
	exit(errno);
}
/**
 * get_env_value - Gets the value of an environment.
 * @env_name: The name of the environment variable.
 * @data: pointer to the data needed to access the environment variables.
 * Return: The value of the environment or NULL.
 */
char *get_env_value(const char *env_name, char **data)
{
	int i;
        int env_len = _strlen(env_name);

	for (i = 0; data[i] != NULL; i++)
	{
		if (strncmp(data[i], env_name, env_len) == 0 && data[i][env_len] == '=')
		{
			return (data[i] + env_len + 1);
		}
	}
        return (NULL);
}

/**
 * _strcompare - Compare two strings case-insensitive.
 * @str1: The first string.
 * @str2: The second string.
 * @n: The maximum number of characters to compare.
 * Return: 1 if the strings are equal, otherwise 0.
 */
int _strcompare(const char *str1, const char *str2, int n)
{
	int i = 0;

	while (str1[i] && str2[i] && (i < n || n == 0))
	{
		if (_islower(str1[i]) != _islower(str2[i]))
			return (0);
		i++;
	}
	if (i == n || n == 0)
		return (1);
	return (0);
}

/**
 * set_working_dir - Change the working directory.
 * @data: A pointer to the data needed to change the working directory.
 * @dir: The new working directory.
 * Return: 0 on success, -1 on failure.
 */
int set_working_dir(const char *dir)
{
	char old_dir[128] = {0};
	char *pwd_value;

	if (chdir(dir) == -1)
	{
		perror("chdir error");
		return (-1);
	}

	pwd_value = getenv("PWD");
	if (pwd_value == NULL)
	{
		printf("PWD environment variable not found.\n");
		return (-1);
	}
	if (setenv("OLDPWD", pwd_value, 1) == -1)
	{
		perror("Failed to update OLDPWD environment variable");
		return (-1);
	}

	if (getcwd(old_dir, 128) == NULL)
	{
		perror("Failed to get current working directory");
		return (-1);
	}
	if (setenv("PWD", old_dir, 1) == -1)
	{
		perror("Failed to update PWD environment variable");
		return (-1);
	}

	return (0);
}
/**
 * builtin_cd - Handles the cd command.
 * @data:  array of arguments.
 * Return: 0 on success, -1 on failure.
 */
int builtin_cd(char **data)
{
	char *dir_home = getenv("HOME"), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data[1])
	{
		if (_strcompare(data[1], "-", 0))
		{
			dir_old = getenv("OLDPWD");
			if (dir_old)
			{
				error_code = set_working_dir(dir_old);
			printf("%s\n", dir_old);
			}
			else
			{
				printf("OLDPWD not found in environment variables.\n");
				error_code = -1;
			}
			return (error_code);
		}
		else
		{
			return (set_working_dir(data[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (set_working_dir(dir_home));
	}
	return (0);
}
