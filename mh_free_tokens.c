#include "mh.h"
/**
 * mh_free_tokens - Free an array of strings
 * @array: An array of tokens
 */
void mh_free_tokens(char **array)
{
	int i;

	if (array == NULL)
	{
		return;
	}
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}
