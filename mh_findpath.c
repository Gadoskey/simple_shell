#include "mh.h"
/**
 * mh_findpath - Find the path of a command
 * @input: the command input
 * Return: A pointer to a char or NULL.
 */
char *mh_findpath(char *input)
{
	char *path, *full_path, *token;
	struct stat size;
	int i;

	if (mh_strlen(input) == 1)
		return (NULL);
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '/')
		{
			if (stat(input, &size) == 0)
				return (mh_strdup(input));
			else
				return (NULL);
		}
	}
	path = mh_getenv("PATH");
	if (path == NULL)
		return (NULL);
	token = strtok(path, ":");
	while (token)
	{
		full_path = malloc(mh_strlen(token) * mh_strlen(input) + 2);
		if (full_path)
		{
			mh_strcpy(full_path, token);
			mh_strcat(full_path, "/");
			mh_strcat(full_path, input);
			if (stat(full_path, &size) == 0)
			{
				free(path);
				return (full_path);
			}
			free(full_path);
			token = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}
