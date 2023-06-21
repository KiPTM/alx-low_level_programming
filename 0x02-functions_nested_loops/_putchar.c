#include "main.h"
#include <unistd.h>

/**
 * main - Entry point
 *_putchar- writes the character to the stdout
 * Return: On Success 1.
 * on error, -1 is Returned 
 */
int _putchar(char c)
{
 	return (write(1, &c, 1));
}
