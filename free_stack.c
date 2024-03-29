#include "monty.h"

/**
 * free_stack - a function that free assigned memory
 * @stack: a linked list data staracture
 * Return: void
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)

	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
