#include "mh.h"
/**
 * mh_tokenize_user_input - Tokenize a string.
 * @input: The string to be tokenized.
 * Return: The number of tokens found in the input string.
 */
char **mh_tokenize_user_input(char *input)
{
	char *delimiter = " \t\n";
	char *token = NULL, *tok = NULL;
	char **command = NULL;
	int i = 0, n = 0;


	if (input == NULL)
		return (NULL);
	tok = mh_strdup(input);
	for (token = strtok(tok, delimiter); token; token = strtok(NULL, delimiter))
	{
		n++;
	}
	free(tok);
	command = malloc(sizeof(char *) * (n + 1));
	if (command == NULL)
	{
		free(input);
		return (NULL);
	}
	token = strtok(input, delimiter);
	for (; token; token = strtok(NULL, delimiter))
	{
		command[i] = mh_strdup(token);
		i++;
	}
	free(input);
	command[i] = NULL;
	return (command);
}
