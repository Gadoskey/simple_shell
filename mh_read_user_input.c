#include "mh.h"
/**
 * read_user_input - read user input
 * Return: A dynamically allocated string containing the user input.
 */
char *read_user_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t size;

	if (isatty(STDIN_FILENO))
	{
		mh_prompt();
	}
	size = (getline(&input, &input_size, stdin));
	if (size == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
