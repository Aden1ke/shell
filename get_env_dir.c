#include "my_shell.h"
/**
 * get_env_value - Gets the value of an environment.
 * @env_name: The name of the environment variable.
 * Return: The value of the environment or NULL.
 */
char *get_env_value(const char *env_name)
{
	char *env_value = getenv(env_name);
	return (env_value);
}

/**
 * update_pwd - Updates the PWD environment.
 * @new_pwd: new current working directory.
 */
void update_pwd(char *new_pwd)
{
	char *old_pwd = get_env_value("PWD");

	if (old_pwd)
	{
		if (setenv("PWD", new_pwd, 1) == -1)
		{
			perror("Failed to update PWD environment variable");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("PWD environment variable not set");
		exit(EXIT_FAILURE);
	}
}
