#include "mh.h"
/**
 * mh_strlen - A program that prints the length of a character
 * @s: The pointer
 * Return: Always 0.
 */
int mh_strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
