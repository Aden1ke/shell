#include "my_shell.h"
/**
 * _strcmp - function that compares two strings.
 * @s1: pointer to the 1st string.
 * @s2: poniter to the 2nd string.
 * Return: Always 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s1[i] == s2[i]; i++)
	;
	return (s1[i] - s2[i]);
}

/**
 * put_char - writes the character to output
 * @s: spec
 * @c: Character
 * Return: 1.
 */
int put_char(int s, char c)
{
	return (write(s, &c, 1));
}

/**
 * put_str - Prints a string to output
 * @s: spec
 * @str: The string
 * Return: 1
 */
int put_str(int s, char *str)
{
	int i;

	if (!str)
		return (put_str(s, "(null)"));
	for (i = 0; str[i]; i++)
		put_char(s, str[i]);

	return (i);
}

/**
 * put_int - Prints an integer to output
 * @s: spec
 * @num: The number
 * Return: 1
 */
int put_int(int s, int num)
{
	int val, len = 0;

	if (!num)
	{
		len += put_char(s, '0');
		return (len);
	}
	if (num == -2147483648)
	{
		len += put_str(s, "-2147483648");
		return (len);
	}
	if (num < 0)
	{
		len += put_char(s, '-');
		num = -num;
	}

	val = num % 10;
	num = num / 10;
	if (num)
		len += put_int(s, num);
	len += put_char(s, val + '0');

	return (len);
}
