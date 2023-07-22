#include "my_shell.h"

/**
 * token_len - Locates the delimiter index marking
 * the end of the first token within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 * Return: The delimiter start marking the end of
 * the intitial token pointed to be str.
 */
int token_len(char *str, char *delim)
{
	int start = 0, len = 0;

	while (*(str + start) && *(str + start) != *delim)
	{
		len++;
		start++;
	}

	return (len);
}

/**
 * count_token - Counts the number of delimited
 * words contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 * Return: The number of words contained within str.
 */
int count_token(char *str, char *delim)
{
	int start, token = 0, len = 0;

	for (start = 0; *(str + start); start++)
		len++;

	for (start = 0; start < len; start++)
	{
		if (*(str + start) != *delim)
		{
			token++;
			start += token_len(str + start, delim);
		}
	}

	return (token);
}

/**
 * _strtok - Tokenizes a string.
 * @str: The string.
 * @delim: The delimiter character to tokenize th
 * string by.
 * Return: A pointer to an array containing the tokenized words.
 */
char **_strtok(char *str, char *delim)
{
	char **ptr;
	int start = 0, token, t, letter, l;

	token = count_token(str, delim);
	if (token == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (token + 2));
	if (!ptr)
		return (NULL);

	for (t = 0; t < token; t++)
	{
		while (str[start] == *delim)
			start++;

		letter = token_len(str + start, delim);

		ptr[t] = malloc(sizeof(char) * (letter + 1));
		if (!ptr[t])
		{
			for (start -= 1; start >= 0; start--)
				free(ptr[start]);
			free(ptr);
			return (NULL);
		}

		for (l = 0; l < letter; l++)
		{
			ptr[t][l] = str[start];
			start++;
		}

		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
