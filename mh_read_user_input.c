#include "mh.h"
/**
 * read_user_input - read user input
 * Return: A dynamically allocated string containing the user input.
 */
char *read_user_input(void)
{
	char *input = NULL;

	if (isatty(STDIN_FILENO))
	{
		mh_prompt();
	}
	input = mh_getline();
	if (input == NULL)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
