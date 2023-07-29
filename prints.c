#include "my_shell.h"

/**
 * prints - Prints to the standar output
 * @s: spec
 * @fmt: Format specifiers
 * @s1: string 1
 * @s2: string 2
 * @num: number
 * Return: Length of string
 */
int prints(int s, const char *fmt, char *s1, int num, char *s2)
{

	int i = 0, len = 0;

	while (fmt[i])
	{
		if (fmt[i] != '%')
			len += put_char(s, fmt[i]);
		else
		{
			i++;
			if (fmt[i] == 'a')
				len += put_str(s, s1);
			else if (fmt[i] == 'b')
				len += put_int(s, num);
			else if (fmt[i] == 'c')
				len += put_str(s, s2);
		}
		i++;
	}

	return (len);
}

/**
 * print_array - prints an array to standard output
 * @array: The array to be printed
 * Return: Numbers of elements.
 */
int print_array(char *array[])
{
	int i = 0;

	while (array[i])
	{
		prints(1, "%a\n", array[i], 0, "nill");
		i++;
	}
	return (0);
}
