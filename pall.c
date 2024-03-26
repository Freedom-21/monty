#include "monty.h"
/**
 * pall - Prints all the values on the stack from the top of the stack
 * @stack: double pointer to the head of the stack
 * Return: void
 */

void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
