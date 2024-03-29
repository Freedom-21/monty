#include "monty.h"

/**
 * is_number - Checks if a string represents a valid integer.
 * @str: The string to check.
 *
 * Return: true if the string represents a valid integer, otherwise false.
 */

bool is_number(const char *str)
{
	int i = 0;

	if (str[0] == '-')
		i = 1;

	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}

	return (true);
}
