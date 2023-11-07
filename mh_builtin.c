#include "mh.h"
/**
 * mh_builtin - checks if command input is builtin
 * @input: the command input
 * Return: 0 or 1
 */
int mh_builtin(char *input)
{
	char *builtin_commands[] = {
		"exit", "env", NULL
	};
	int n = 0;

	while (builtin_commands[n])
	{
		if (mh_strcmp(input, builtin_commands[n]) == 0)
		{
			return (1);
		}
		n++;
	}
	return (0);
}
/**
 * mh_handle_builtin - handle builtin commands
 * @input: input
 * @argv: argv
 * @status: status
 * @index: index
 */
void mh_handle_builtin(char **input, char **argv, int *status, int index)
{
	if (mh_strcmp(input[0], "exit") == 0)
	{
		mh_exit(input, argv, status, index);
	}
	else if (mh_strcmp(input[0], "env") == 0)
	{
		mh_print_env(input, status);
	}
}
/**
 * mh_print_env - print environment variable
 * @input: the exit typed in
 * @status: status
 */
void mh_print_env(char **input, int *status)
{
	int n;

	for (n = 0; environ[n]; n++)
	{
		mh_print(environ[n]);
		mh_print("\n");
	}
	mh_free_tokens(input);
	(*status) = 0;
}
/**
 * mh_exit - exit shell
 * @input: the exit typed in
 * @argv: arguments
 * @status: status
 * @index: index
 */
void mh_exit(char **input, char **argv, int *status, int index)
{
	int value = (*status);
	char *token, message[] = ": exit: Illegal number: ";

	if (input[1])
	{
		if (mh_is_positive(input[1]))
		{
			value = mh_atoi(input[1]);
		}
		else
		{
			token = mh_itoa(index);
			mh_print2(argv[0]);
			mh_print2(": ");
			mh_print2(token);
			mh_print2(message);
			mh_print2(input[1]);
			mh_print2("\n");
			free(token);
			mh_free_tokens(input);
			(*status) = 2;
			return;
		}
	}
	mh_free_tokens(input);
	exit(value);
}
/**
 * mh_is_positive - checks if a num is positive
 * @string: the string to be checked
 * Return: 0 or 1
 */
int mh_is_positive(char *string)
{
	int num;

	if (string == NULL)
	{
		return (0);
	}

	num = 0;
	while (string[num])
	{
		if (string[num] < '0' || string[num] > '9')
		{
			return (0);
		}
		num++;
	}
	return (1);
}
