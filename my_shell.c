#include "my_shell.h"
<<<<<<< HEAD
char *name = NULL;
int incr = 0;
bool should_exit = false;
=======

>>>>>>> 1eee9c11927c4b308f76dec0ebf588aab8e9ac1c
/**
 * main - Simple shell program that runs shell commands
 * similar to the bash script
 * @argc: number count
 * @argv: argument vector.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	bool pipe = false;

	argc = argc;
	argv = argv;
	if (!isatty(STDIN_FILENO))
		pipe = true;
	if (!pipe)
	{
		return (handle_interactive_mode());
	}
	else
	{
		return (handle_non_interactive_mode());
	}
}


/**
<<<<<<< HEAD
 * handle_interactive_mode - Handle shell command
 * in interactive mode
 * Return: void.
 */
int handle_interactive_mode(void)
{
	char *start = "$ ";
	char *buf = NULL;
	ssize_t data;
	size_t size = 0;
	int p_status, builtin_status;

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
		builtin_status = handle_builtin(buf, NULL);
		if (builtin_status != -1)
		{
			free(buf);
			return (builtin_status);
		}
		if (should_exit)
		{
			free(buf);
			return (0);
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
 * handle_non_interactive_mode - Handle shell commands
 * when reading from a pipe
 * Return: void.
 */
int handle_non_interactive_mode(void)
{
	char *buf = NULL;
	ssize_t data;
	size_t size = 0;
	int p_status, builtin_status;

	while (1)
	{
		data = my_getline(&buf, &size, stdin);
		if (data == -1)
			break;

		if (buf[data - 1] == '\n')
			buf[data - 1] = '\0';

		builtin_status = handle_builtin(buf, NULL);
		if (builtin_status != -1)
		{
			free(buf);
			return (builtin_status);
		}
		if (should_exit)
		{
			free(buf);
			return (0);
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
/**
=======
>>>>>>> 1eee9c11927c4b308f76dec0ebf588aab8e9ac1c
 * handle_fork_process - handle fork process
 * to create reapeted process
 * @command: string to break down
 * Return: p_sta.
 */
int handle_fork_process(char *command)
{
	pid_t my_pid;
	int p_stat, exit_status;

	my_pid = fork();
	if (my_pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (my_pid == 0)
	{
		handle_arguments(command);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(my_pid, &p_stat, 0);
		if (WIFEXITED(p_stat))
		{
			exit_status = WEXITSTATUS(p_stat);
			fflush(stdout);
			return (exit_status);
		}
	}
	return (0);
}

/**
 * handle_builtin - Handle built-in shell commands
 * @command: The command to handle
 * @args: arguments
 * Return: Return status for built-in commands, -1 if not a built-in command.
 */
int handle_builtin(char *command, char **args)
{
	if (_strcmp(command, "env") == 0)
	{
		print_array(environ);
		return (-1);
	}
	else if (_strcmp(command, "exit") == 0)
	{
		if (args == NULL || args[1] == NULL)
			return (0);
		else
			return (handle_exit_command(args));
	}
	else if (_strcmp(command, "cd") == 0)
	{
		return (handle_cd_command(&command));
	}

	return (-1);
}
