#include "my_shell.h"

/**
 * main - Simple shell program that runs shell commands
 * similar to the bash script
 * @ac: argument count
 * @*av[]: argument vector
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	bool pipe = false;
	char *start = "$ ", *buf = NULL;
	ssize_t data;
	size_t size = 0;
	pid_t my_pid;
	int p_stat;
	argc = argc;
	argv = argv;
		
	while(1 && !pipe)
	{
		if(isatty(STDIN_FILENO) == 0)
			pipe = true;
		
		write(STDOUT_FILENO, start, 2);

		data = getline(&buf, &size, stdin);
		if(data == -1)
		{
			perror("getline error");
			free(buf);
		}

		if(buf[data - 1] == '\n')
			buf[data - 1] = '\0';

		my_pid = fork();
		if(my_pid < 0)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		if(my_pid == 0)
		{
			handle_arguments(buf);
		}

		waitpid(my_pid, &p_stat, 0);
		if(p_stat != 0)
		{	
			perror("wait error");
			exit(EXIT_FAILURE);
		}
	}
	free(buf);
	return(0);
}
