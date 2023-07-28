#include "my_shell.h"
/**
 * *_calloc - function that allocates memory for an array
 * using malloc.
 * @nmemb: number of elements.
 * @size: size of each element in bytes.
 * Return: Always 0.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	 void *ptr;
	 unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if(!ptr)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		((char *) (ptr))[i] = 0;

	return (ptr);
}
