#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the beginning of the stack
 *@line_number: Line number in the Monty bytecode file
 * Return: voi
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
