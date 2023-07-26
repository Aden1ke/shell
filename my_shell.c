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
	while (1 && !pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe = true;
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
			exit(98);
		}

	}
	free(buf);
	buf = NULL;
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
	int p_stat;

	my_pid = fork();
	if (my_pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (my_pid == 0)
	{
		handle_arguments(command);
	}
	waitpid(my_pid, &p_stat, 0);
	return (p_stat);
}
