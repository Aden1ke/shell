#include "my_shell.h"
/**
 * get_env_value - Gets the value of an environment.
 * @env_name: The name of the environment variable.
 * Return: The value of the environment or NULL.
 */
char *get_env_value(const char *env_name)
{
	char **env = environ;
	int env_name_len = _strlen(env_name);

	while (*env)
	{
		if (_strncmp(env_name, *env, env_name_len) == 0)
		{
			return (*env + env_name_len + 1);
		}
		env++;
    }
    return (NULL);
}

/**
 * update_pwd - Updates the PWD environment.
 * @new_pwd: new current working directory.
 */
void update_pwd(char *new_pwd)
{
	char *old_pwd = get_env_value("PWD");
	char *env_str;

	if (old_pwd)
	{
		env_str = _strcat("PWD=", new_pwd);
		if (env_str)
		{
			if (setenv("PWD", new_pwd, 1) == -1)
			{
				perror("Failed to update PWD environment variable");
				exit(EXIT_FAILURE);
			}
			printf("New PWD: %s\n", new_pwd);
		}
		else
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("PWD environment variable not set");
		exit(EXIT_FAILURE);
	}
	if (chdir(new_pwd) == -1)
	{
		perror("cd error");
		exit(EXIT_FAILURE);
	}
}
