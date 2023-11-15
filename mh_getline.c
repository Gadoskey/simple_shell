#include "mh.h"
/**
 * mh_getline - custom getline
 * Return: char
 */
char *mh_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos;
	static int bytes_read;
	char *line = NULL;
	int line_pos = 0;
	int buffer_empty = 1;
	char current_char;

	while (1)
	{
		if (buffer_empty)
		{
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
			{
				if (line != NULL)
				{
					free(line);
				}
				return (NULL);
			}
			buffer_empty = 0;
			buffer_pos = 0;
		}
		current_char = buffer[buffer_pos++];
		if (current_char == '\n'|| current_char == EOF)
		{
			if (line == NULL)
				return (NULL);
			line[line_pos] = '\0';
			return (line);
		}
		if (line == NULL)
			line = (char *)malloc(BUFFER_SIZE);
		else if (line_pos >= BUFFER_SIZE - 1)
			line = (char *)realloc(line, BUFFER_SIZE * 2);
		line[line_pos++] = current_char;
		if (buffer_pos == bytes_read)
			buffer_empty = 1;
	}
}
