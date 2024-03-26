#include "monty.h"

/**
 * main - program entry point
 * Return: Exit with success
 */

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE_LENGTH];

	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		parse_and_execute(&stack, line);
	}

	fclose(file);

	return (EXIT_SUCCESS);
}
