#include "mh.h"
/**
 * mh_execute_command - Execute command
 * @command: command
 * @argv: arguments
 * Return: status
 */
int mh_execute_command(char **command, char **argv)
{
	pid_t child_pid;
	int status;

	if (command == NULL || command[0] == NULL)
	{
		mh_free_tokens(command);
		return (0);
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			mh_free_tokens(command);
			exit(1);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		mh_free_tokens(command);
	}
	return (WEXITSTATUS(status));
}
