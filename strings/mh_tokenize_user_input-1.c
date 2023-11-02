#include "mh.h"
/**
 * mh_tokenize_user_input - Tokenize a string.
 * @input: The string to be tokenized.
 * Return: The number of tokens found in the input string.
 */
char **mh_tokenize_user_input(char *input)
{
	char *delimiter = " \t\n";
	char *token = NULL, *tokens = NULL;
	char **command = NULL;
	int i = 0, n = 0;


	if (input == NULL)
		return (NULL);
	tokens = mh_strdup(input);
	token = strtok(tokens, delimiter);
	while (token)
	{
		n++;
		token = strtok(NULL, delimiter);
	}
	free(tokens);
	command = malloc(sizeof(char *) * (n + 1));
	if (command == NULL)
	{
		free(input);
		return (NULL);
	}
	token = strtok(input, delimiter);
	while (token)
	{
		command[i] = mh_strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	free(input);
	command[i] = NULL;
	return (command);
}
