#include "mh.h"
/**
 * mh_print_error - prints error
 * @input: input
 * @command: command
 * @index: index
 */
void mh_print_error(char *input, char *command, int index)
{
	char *token;
	char delimiter[] = ": ", message[] = ": not found\n";

	token = mh_itoa(index);
	mh_print2(input);
	mh_print2(delimiter);
	mh_print2(token);
	mh_print2(delimiter);
	mh_print2(command);
	mh_print2(message);
	free(token);
}
/**
 * mh_itoa - converts an int to ascii
 * @num: index
 * Return: buffersize
 */
char *mh_itoa(int num)
{
	char buff_size[20];
	int size = 0;

	if (num == 0)
	{
		buff_size[size++] = '0';
	}
	else
	{
		while (num > 0)
		{
			buff_size[size++] = (num % 10) + '0';
			num /= 10;
		}
	}
	buff_size[size] = '\0';
	mh_reverse_string(buff_size, size);

	return (mh_strdup(buff_size));
}
/**
 * mh_atoi - converts ascii to an int
 * @string: the string
 * Return: number
 */
int mh_atoi(char *string)
{
	int j, number = 0;

	j = 0;
	while (string[j])
	{
		number *= 10;
		number += (string[j] - '0');
		j++;
	}
	return (number);
}
/**
 * mh_reverse_string - reverses a string
 * @string: the string
 * @length: legth of the string
 */
void mh_reverse_string(char *string, int length)
{
	char temp;
	int start = 0, end;

	end = length - 1;
	for (; start < end; start++, end--)
	{
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;
	}
}
