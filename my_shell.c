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
		int status = handle_arguments(command);

		exit(status);
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
