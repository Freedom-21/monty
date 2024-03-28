#include "monty.h"

/**
 * add - a function that adds the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int first_op;
	int sec_op;
	int result;

	if (!*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first_op = (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);

	sec_op = (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);

	result = first_op + sec_op;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->n = result;
	temp->prev = NULL;
	temp->next = *stack;
	if (*stack)
		(*stack)->prev = temp;
	*stack = temp;
}
