#include "my_shell.h"

/**
 * exit_status - exits the shell with a status
 * @exit_stat: the exit status
 * Return: -2 on failure
 */
int exit_status(char *exit_stat)
{
	if (!exit_stat)
	{
		free(buffer);
		free_array(command);
		exit(stat_);
	}

	stat_ = _atoi(exit_stat);

	if (stat_ >= 0)
	{
		free(buffer);
		free_array(command);
		exit(stat_);
	}

	prints(2, "%a: %b: exit: ", shell, first, "nill");
	prints(2, "Illegal number: %a\n", exit_stat, 0, "nill");

	return (2);
}
