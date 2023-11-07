#include "mh.h"
/**
 * mh_print2 - prints a text to standard error
 * @text: The message to be printed.
 */
void mh_print2(char *text)
{
	write(STDERR_FILENO, text, strlen(text));
}
