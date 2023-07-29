#include "my_shell.h"

/**
 * handle_interactive_mode - Handle shell commands in interactive mode
 */
int handle_interactive_mode(void)
{
	char *start = "$ ";
	char *buf = NULL;
	ssize_t data;
	size_t size = 0;
	int p_status;

	while (1)
	{
		write(STDOUT_FILENO, start, 2);
		data = my_getline(&buf, &size, stdin);
		if (data == -1)
		{
			perror("getline error");
			free(buf);
			continue;
		}

		if (buf[data - 1] == '\n')
			buf[data - 1] = '\0';

		if (_strcmp(buf, "env") == 0)
		{
			p_status = print_array(environ);
			free(buf);
			return (p_status);
		}

		if (_strcmp(buf, "exit") == 0)
		{
			handle_arguments(buf);
			free(buf);
			exit(1000);
		}
		else
		{
			p_status = handle_fork_process(buf);
			if (p_status != 0 && p_status != END_OF_FILE)
				return (p_status);

		}
	}
	free_buffer(&buf);
	return (0);
}

/**
 * handle_non_interactive_mode - Handle shell commands when reading from a pipe
 */
int handle_non_interactive_mode(void)
{
	char *buf = NULL;
	ssize_t data;
	size_t size = 0;
	int p_status;

	while (1)
	{
		data = my_getline(&buf, &size, stdin);
		if (data == -1)
			break;

		if (buf[data - 1] == '\n')
			buf[data - 1] = '\0';

		if (_strcmp(buf, "env") == 0)
		{
			p_status = print_array(environ);
			free(buf);
			return (p_status);
		}

		if (_strcmp(buf, "exit") == 0)
		{
			handle_arguments(buf);
			free(buf);
			exit(1000);
		}
		else
		{
			p_status = handle_fork_process(buf);
			free_buffer(&buf);
			if (p_status != 0)
			{
				return (p_status);
				exit(EXIT_SUCCESS);
			}
		}
	}
	free_buffer(&buf);
	return (0);
}
