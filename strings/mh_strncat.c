#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _strncat - copies a string into another string
 * @dest: The first pointer
 * @n: The integer
 * @src: The second pointer
 * Return: Always 0.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*src != '\0' && n > 0)
	{
		*ptr = *src;
		ptr++;
		src++;
		n--;
	}
	*ptr = '\0';
	return (dest);
}
