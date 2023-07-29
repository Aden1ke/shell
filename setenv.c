#include "my_shell.h"

/**
 * _setenv - adds an environmental variable to the PATH.
 * @args: An array of arguments
 * Return: If error  -1. Otherwise - 0.
 */
int _setenv(char **args)
{
	char *env_var = NULL, **new_env, *new_val;
	size_t size;
	int index;

	if (!args[0] || !args[1])
		return (-1);

	new_val = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_val)
		return (-1);
	_strcpy(new_val, args[0]);
	_strcat(new_val, "=");
	_strcat(new_val, args[1]);

	env_var = get_env(args[0]);
	if (env_var)
	{
		free(env_var);
		env_var = new_val;
		return (0);
	}
	for (size = 0; environ[size]; size++)
		;

	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
	{
		free(new_val);
		return (-1);
	}

	for (index = 0; environ[index]; index++)
		new_env[index] = environ[index];

	free(environ);
	environ = new_env;
	environ[index] = new_val;
	environ[index + 1] = NULL;

	return (0);
}

/**
 * _unsetenv - Deletes an environmental variable from the PATH.
 * @args: An array of arguments
 * Return: If error -1. Otherwise - 0.
 */
int _unsetenv(char **args)
{
	char *env_var, **new_env;
	size_t size;
	int index, index2;

	if (!args[0])
		return (-1);
	env_var = get_env(args[0]);
	if (!env_var)
		return (0);

	for (size = 0; environ[size]; size++)
		;

	new_env = malloc(sizeof(char *) * size);
	if (!new_env)
		return (-1);

	for (index = 0, index2 = 0; environ[index]; index++)
	{
		if (env_var == environ[index])
		{
			free(env_var);
			continue;
		}
		new_env[index2] = environ[index];
		index2++;
	}
	free(environ);
	environ = new_env;
	environ[size - 1] = NULL;

	return (0);
}
