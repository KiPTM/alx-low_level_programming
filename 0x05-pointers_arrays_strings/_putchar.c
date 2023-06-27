#include <unistd.h>

/**
 * _putchar - writes a character to the standard output
 * @c: the character to print
 *
 * Return: On success, return the number of characters written.
 * On error, return -1 and set errno appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
