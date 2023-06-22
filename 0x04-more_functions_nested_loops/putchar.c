#include <unistd.h>

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 *
 * Return: On success, return the number of characters written.
 *         On error, return -1.
 */
int _putchar(char c)
{
  return write(1, &c, 1);
}
