#include "mh.h"
/**
 * mh_strtok - custom strtok
 * @str: string
 * @delim: delimiter
 * Return: token_start
 */
char *mh_strtok(char *str, const char *delim)
{
	char *token;
	static char *last;
	int i, j;

	if (str == NULL)
	{
		str = last;
	}
	while (*str && strchr(delim, *str))
	{
		str++;
	}
	if (!*str)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] && !strchr(delim, str[i]))
	{
		i++;
	}
	token = (char *) malloc(i + 1);
	if (token == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		token[j] = str[j];
	}
	token[j] = '\0';
	last = str + i;
	return (token);
}
