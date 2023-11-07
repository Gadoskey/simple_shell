#include "mh.h"
/**
 * mh_execute_command - Execute command
 * @command: command
 * @index: index
 * @argv: arguments
 * Return: status
 */
int mh_execute_command(char **command, char **argv, int index)
{
	char *full_command;
	pid_t child_pid;
	int status;

	full_command = mh_findpath(command[0]);
	if (full_command == NULL)
	{
		mh_print_error(argv[0], command[0], index);
		mh_free_tokens(command);
		return (1);
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(full_command, command, environ) == -1)
		{
			free(full_command);
			mh_free_tokens(command);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		mh_free_tokens(command);
		free(full_command);
	}
	return (WEXITSTATUS(status));
}
