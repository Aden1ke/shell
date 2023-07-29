#include "my_shell.h"
/**
 * get_env - Gets the env from the path.
 * @var: The name of the env variable.
 * Return: If no env variable - NULL.
 * Otherwise - a pointer to the env variable.
 */
char *get_env(const char *var)
{
	int i, len = _strlen(var);
	char *val = NULL;

	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp(environ[i], var, len) && environ[i][len] == '=')
		{
			val = environ[i] + _strlen(var) + 1;
			return (val);
		}
	}
	return (val);
}
