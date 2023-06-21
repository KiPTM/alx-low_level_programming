#include "main.h"

/**
 * _islower - check if char is lowercase
 * @c: is the char to be checked
 * written by Tuwei
 * Return: 1 if char is lowercase, else 0.
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
