#include "monty.h"

/**
 * is_number - Checks if a string represents a valid integer.
 * @str: The string to check.
 *
 * Return: true if the string represents a valid integer, otherwise false.
 */

bool is_number(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (false);
		}
		str++;
	}

	return (true);
}
