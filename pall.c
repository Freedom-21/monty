#include "monty.h"
/**
 * pall - Prints all the values on the stack from the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
