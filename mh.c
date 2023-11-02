#include "mh.h"
/**
 * main - The program's entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *user_input;
	char **command = NULL;
	int status = 0;

	(void)argc;
	while (1)
	{
		user_input = read_user_input();
		if (user_input == NULL)
		{
			if (isatty(STDIN_FILENO))
				mh_print("\n");
			return (status);
		}
		command = mh_tokenize_user_input(user_input);
		if (command == NULL)
			continue;
		status = mh_execute_command(command, argv);
	}
	return (0);
}
