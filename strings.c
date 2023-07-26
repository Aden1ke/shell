#include "my_shell.h"
/**
 * _strlen - Returns the length of a string.
 * @str: A pointer to the characters string.
 * Return: The length of the character string.
 */
int _strlen(const char *str)
{
	int len = 0;

	if (!str)
		return (len);
	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * _strcat - Concantenates two strings.
 * @dest: Pointer to destination string.
 * @str: Pointer to string.
 * Return: Pointer to destination string.
 */
char *_strcat(char *dest, const char *str)
{
	char *dest1;
	const char *str1;

	dest1 = dest;
	str1 =  str;

	while (*dest1 != '\0')
		dest1++;

	while (*str1 != '\0')
		*dest1++ = *str1++;
	*dest1 = '\0';
	return (dest);
}

/**
 * _strncat - Concantenates two strings where
 * number of bytes are copied.
 * @dest: Pointer to destination string.
 * @str: Pointer to string.
 * @n: n bytes to copy from str.
 * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *str, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && str[i] != '\0'; i++)
		dest[dest_len + i] = str[i];
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strncmp - Compare two strings where the
 * number of bytes are copied
 * @str1: Pointer to a string.
 * @str2: Pointer to a string.
 * @n: The first n bytes of the strings.
 * Return: Less than 0 if str1 is shorter than
 * str2. 0 if str1 and str2 match. Greater
 * than 0 if str1 is longer than str2.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; str1[i] && str2[i] && i < n; i++)
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		else if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
