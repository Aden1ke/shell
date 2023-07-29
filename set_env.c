#include "my_shell.h"

/**
 * _env - Prints the current environment.
 * @args: An array of arguments passed to the shell.
 * Return: -1
 */
int _env(char **args)
{
	int index;
	char nl = '\n';
	
	if (!environ)
		return (-1);
	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &nl, 1);
	}

	(void)args;
	return (0);
}

/**
 * _setenv - Changes or adds an environmental variable to the PATH.
 * @args: An array of arguments passed to the shell.
 * Return: If an error occurs - -1
 */
int _setenv(char **args)
{
	char **env_var = NULL, **new_env, *new_val;
	size_t size;
	int index;

	if (!args[0] || !args[1])
	{
		perror("setenv error");
		return (-1);
	}
	new_val = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_val)
	{
		perror("unset1 error");
		return (-1);
	}
	_strcpy(new_val, args[0]);
	_strcat(new_val, "=");
	_strcat(new_val, args[1]);
	env_var = get_env(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_val;
		return (0);
	}
	for (size = 0; environ[size]; size++)
		;
	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
	{
		free(new_val);
		perror("setenv2 error");
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
 * @args: An array of arguments passed to the shell.
 * Return: If an error occurs - -1.
 */
int _unsetenv(char **args)
{
	char **env_var, **new_env;
	size_t size;
	int index, index2;

	if (!args[0])
	{
		perror("unsetenv error");
		return (-1);
	}
	env_var = get_env(args[0]);
	if (!env_var)
		return (0);
	for (size = 0; environ[size]; size++)
		;
	new_env = malloc(sizeof(char *) * size);
	if (!new_env)
	{
		perror("unsetenv1 error");
		return (-1);
	}
	for (index = 0, index2 = 0; environ[index]; index++)
	{
		if (*env_var == environ[index])
		{
			free(*env_var);
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
