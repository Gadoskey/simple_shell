#include "mh.h"
/**
 * mh_print - prints a text
 * @text: The message to be printed.
 */
void mh_print(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
}
