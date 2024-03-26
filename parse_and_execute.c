#include "monty.h"

/**
 * parse_and_execute - Parses and executes Monty bytecode instructions
 * @stack: Double pointer to the head of the stack
 * @line: Pointer to the string to the monty bytecode instruction
 * Return: void
 */

void parse_and_execute(stack_t **stack, char *line)
{
	char *opcode, *arg;
	int line_number = 0;

	if (!line)
		return;

	opcode = strtok(line, " \n");

	if (!opcode || opcode[0] == '#')
		return;

	arg = strtok(NULL, " \n");
	line_number++;

	if (strcmp(opcode, "push") == 0)
	{
		if (!arg || !is_number(arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, line_number, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
