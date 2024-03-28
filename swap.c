#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->prev = (*stack)->prev;

	if (temp->next != NULL)
		temp->next->prev = *stack;
	(*stack)->prev = temp;
	temp->next = *stack;
	*stack = temp;
}

