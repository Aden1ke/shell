#include "shell.h"
/**
 * main - creating a shell(entry point of the shell
 * @argc: number of arguments
 * @argv: arguments inputed.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	char *string = NULL, *token;
	size_t len = 0, i = 0;
	int command;

	argc = argc;
	command = getline(&string, &len, stdin);
	if (command == -1)
	{
		return (-1);
	}
	token = strtok(string, " ");
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");	
	}
	argv[i] = NULL;
	if (execve(argv[0], argv, NULL) == -1)
	{
		printf("argv[0]");
		perror("Error:");
	}
	free(string);
	return (0);
}
