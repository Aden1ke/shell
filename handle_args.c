#include "my_shell.h"
/**
 * handle_args - handle arguments
 * @argc: number of arguments
 * @argv: arguments inputed.
 * Return: 0.
 */
void handle_arguments(char *line)
{
        char *command[1000], *token;
        int i = 0;

	token = strtok(line, "\n");
	while (token != NULL)
        {
                command[i++] = token;
                token = strtok(NULL, "\n");
        }
	command[i] = NULL;
	if (execve(command[0], command, NULL) == -1)
	{
		printf("argv[0]");
		perror("Error:");
	}
}
