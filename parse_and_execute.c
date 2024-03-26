#include "monty.h"

/**
 * parse_and_execute - Parses and executes Monty bytecode instructions
 * @stack: Double pointer to the head of the stack
 * @line: Pointer to the string to the monty bytecode instruction
 * Return: void
 */

void parse_and_execute(stack_t **stack, char *line)
{
	char *opcode;
	int line_number = 0;
	instruction_t *inst;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	if (!line)
		return;

	opcode = strtok(line, " \n");

	if (!opcode || opcode[0] == '#')
		return;

	line_number++;

	for (inst = instructions; inst->opcode != NULL; inst++)
	{
		if (strcmp(opcode, inst->opcode) == 0)
		{
			inst->f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
