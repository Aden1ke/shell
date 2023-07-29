#include "my_shell.h"
/**
 * _strcpy - Copies the string pointed to by str,
 * with the terminating null byte, to the buffer.
 * @dest: Pointer to the destination of  string.
 * @str: Pointer to the str of the string.
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * len_num - Counts the length of a num.
 * @num: The number
 * Return: The length.
 */
int len_num(int num)
{
	unsigned int numb;
	int len = 1;

	if (num < 0)
	{
		len++;
		numb = num * -1;
	}
	else
	{
		numb = num;
	}
	while (numb > 9)
	{
		len++;
		numb /= 10;
	}

	return (len);
}

/**
 * _itoa - Converts an integer to a string.
 * @num: The integer.
 * Return: The converts
 */
char *_itoa(int num)
{
	char *buf;
	int len = len_num(num);
	unsigned int numb;

	buf = malloc(sizeof(char) * (len + 4));
	if (!buf)
		return (NULL);

	buf[len] = '\0';

	if (num < 0)
	{
		numb = num * -1;
		buf[0] = '-';
	}
	else
	{
		numb = num;
	}

	len--;
	do {
		buf[len] = (numb % 10) + '0';
		numb /= 10;
		len--;
	} while (numb > 0);

	return (buf);
}
