#include "monty.h"

/**
 * parse_and_execute - Parses and executes Monty bytecode instructions
 * @stack: Double pointer to the head of the stack
 * @line_number: line number in the monty bytecode file
 * @line: Pointer to the string to the monty bytecode instruction
 * Return: void
 */

void parse_and_execute(stack_t **stack, char *line, int line_number)
{
	char *opcode;
	instruction_t *inst;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	if (!line)
		return;
	while (*line && isspace(*line))
		line++;
	if (*line == '\0' || *line == '#')
		return;
	opcode = strtok(line, " \t\n");

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
