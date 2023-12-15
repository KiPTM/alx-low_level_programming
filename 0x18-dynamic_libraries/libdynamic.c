#include <stdio.h>
#include "main.h"

int _putchar(char c) {
    /* Implementation of _putchar function
     *  Add your implementation here
     */
    return 0;
}

int _islower(int c) {
    /* Implementation of _islower function */
    /* Add your implementation here */
    return 0;
}

int _isalpha(int c) {
    /* Implementation of _isalpha function */
    /* Add your implementation here */
    return 0;
}

/* Implementations of other listed functions */

char *_strstr(char *haystack, char *needle)
{
    /* Implementation of _strstr function */
    /* Add your implementation here */
       	return NULL;
}

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c: int to be checked
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _puts- a functions that prints a string followed by a new line
 * tp stdout
 * @str: input string
 * Return: void
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

/**
* _strncat- function that concatenates two strings.
* @dest: destination string pointer
* @src: source string pointer
* @n: number of bytes to be concatenated.
* Return: destination string pointer
*/
char *_strncat(char *dest, char *src, int n)
{
	int len, z;

	len = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	for (z = 0; z < n && src[z] != '\0'; z++, len++)
	{
		dest[len] = src[z];
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _atoi - a function that converts string to integer
 * @s:pointer to an  input string
 * Return: integer from conversion
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			null_flag = 1;
			total = total * 10 + *s - '0';
		}

		else if (null_flag)
			break;
		s++;
	}

	if (sign < 0)
		total = (-total);

	return (total);
}

}
