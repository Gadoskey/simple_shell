#include "mh.h"
/**
 * mh_getenv - get environment variables
 * @input: the environmenty variable
 * Return: a pointer to a char
 */
char *mh_getenv(char *input)
{
	char *token1, *token2, *token3, *env;
	int i = 0;

	while (environ[i])
	{
		token1 = mh_strdup(environ[i]);
		token2 = strtok(token1, "=");
		if (mh_strcmp(token2, input) == 0)
		{
			token3 = strtok(NULL, "\n");
			env = mh_strdup(token3);
			free(token1);
			return (env);
		}
		free(token1);
		i++;
	}
	return (NULL);
}
