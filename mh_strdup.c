#include "mh.h"
/**
 * mh_strdup - Duplicate a string.
 * @string: The string to be duplicated.
 * Return: A copy of the input string, or NULL.
 */
char *mh_strdup(const char *string)
{
	char *duplicate;
	int i, length = 0;

	if (string == NULL)
	{
		return (NULL);
	}
	while (*string != '\0')
	{
		length++;
		string++;
	}
	string = string - length;
	duplicate = malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= length; i++)
	{
		duplicate[i] = string[i];
	}
	return (duplicate);
}
