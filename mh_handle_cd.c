#include "mh.h"
/**
 * mh_handle_cd - handles cd command
 * @command: the command
 */
void mh_handle_cd(char *command)
{
	char *destinationDirectory = NULL;
	char *currentDirectory;

	if (command == NULL)
	{
		destinationDirectory = mh_getenv("HOME");
	}
	else if (strcmp(command, "-") == 0)
	{
		destinationDirectory = mh_getenv("OLDPWD");
	}
	else
	{
		destinationDirectory = mh_strdup(command);
	}
	if (chdir(destinationDirectory) != 0)
	{
		mh_print2("Error: failed to change to directory\n");
	}
	free(destinationDirectory);
	currentDirectory = malloc(sizeof(char) * MAX_COMMAND_LENGTH);

	if (getcwd(currentDirectory, MAX_COMMAND_LENGTH) != NULL)
	{
		setenv("PWD", currentDirectory, 1);
	}
	free(currentDirectory);
}
