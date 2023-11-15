#include "mh.h"
/**
 * mh_tokenize_user_input - Tokenize a string.
 * @input: The string to be tokenized.
 * Return: The number of tokens found in the input string.
 */
char **mh_tokenize_user_input(char *input)
{
	char *delim = " \t\n";
	char *token = NULL, *tok1 = NULL;
	char **command = NULL;
	int i = 0, n = 0;


	if (input == NULL)
		return (NULL);
	tok1 = mh_strdup(input);
	for (token = strtok(tok1, delim); token; token = strtok(NULL, delim))
	{
		n++;
	}
	free(tok1);
	tok1 = NULL;
	command = malloc(sizeof(char *) * (n + 1));
	if (command == NULL)
	{
		return (NULL);
	}
	token = strtok(input, delim);
	for (; token; token = strtok(NULL, delim))
	{
		command[i] = mh_strdup(token);
		i++;
	}
	command[i] = NULL;
	free(input);
	return (command);
}
