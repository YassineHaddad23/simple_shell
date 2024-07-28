#include "main.h"

/**
 * _atoi - Convert a string to an integer.
 * @s: The string to convert.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	while (*s != '\0' && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}

	while (*s != '\0' && (*s >= '0' && *s <= '9'))
	{
		num = num * 10 + (*s - '0');
		s++;
	}

	return (num * sign);
}
