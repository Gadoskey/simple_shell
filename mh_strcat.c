#include "mh.h"

/**
 * mh_strcat - copies a string into another string
 * @dest: The first pointer
 * @src: The second pointer
 * Return: Always 0.
 */
char *mh_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);


}
