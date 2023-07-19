#include "my_shell.h"
/**
 * handle_arguments - handle arguments
 * @line: string to break down
 * Return: void.
 */
void handle_arguments(char *line)
{
	char *command[1000], *token;
	int i = 0;

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		command[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	command[i] = NULL;
	if (strcmp(command[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	if (execve(command[0], command, NULL) == -1)
	{
		perror("Error");
	}
}
/**
 * _strcmp - function that compares two strings.
 * @s1: pointer to the 1st string.
 * @s2: poniter to the 2nd string.
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s1[i] == s2[i]; i++)
		;
	return (s1[i] - s2[i]);
}
