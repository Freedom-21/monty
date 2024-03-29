#include "monty.h"

/**
 * main - program entry point
 * Return: Exit with success
 */

#define MAX_LINE_LENGTH 2048

int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE_LENGTH];
	int line_number = 0;

	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s <filename>\n", argv[0]);
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
		line_number++;
		parse_and_execute(&stack, line, line_number);
	}

	fclose(file);

	return (EXIT_SUCCESS);
}
