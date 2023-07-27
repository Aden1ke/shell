#include "my_shell.h"
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
	char *start = "$ ", *buf = NULL;
	ssize_t data;
	size_t size = 0;
	int p_status;

	argc = argc;
	argv = argv;
	if (!isatty(STDIN_FILENO))
		pipe = true;
	
	if (!pipe)
	{
		while (!pipe)
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
			p_status = handle_fork_process(buf);
			if (p_status != 0)
			{
				return (p_status);
			}
		}
	}
	else
	{
		p_status = handle_piped_input(buf, size);
		return p_status;
	}
	free_buffer(&buf);
	return (0);
}
/**
 * handle_piped_input - handle piping process
 * @buff: string to break down
 * @size: buff size
 * Return: p_sta.
 */
int handle_piped_input(char *buf, size_t size)
{
	ssize_t data;
	int p_status;

	while (1)
	{
		data = my_getline(&buf, &size, stdin);
		if (data == -1)
			break;

		if (buf[data - 1] == '\n')
		buf[data - 1] = '\0';

		p_status = handle_fork_process(buf);
		if (p_status != 0)
		{
			return (p_status);
		}
	}
	return (0);
}

/**
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
		exit(EXIT_FAILURE);
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
 * free_buffer - handle arguments
 * @buffer: string to break down
 * Return: void.
 */
void free_buffer(char **buffer)
{
	if (buffer != NULL && *buffer != NULL)
	{
		free(*buffer);
		*buffer = NULL;
	}
}
