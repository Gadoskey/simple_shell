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
	int status = 0, index = 0;

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
		index++;
		command = mh_tokenize_user_input(user_input);
		if (command == NULL || command[0] == NULL)
		{
			mh_free_tokens(command);
			continue;
		}
		else if (mh_builtin(command[0]))
			mh_handle_builtin(command, argv, &status, index);
		else if (mh_strcmp(command[0], "cd") == 0)
		{
			mh_handle_cd(command[1]);
			mh_free_tokens(command);
		}
		else
			status = mh_execute_command(command, argv, index);
	}
}
