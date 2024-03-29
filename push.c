#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;
	stack_t *new_node;

	arg = strtok(NULL, " \t\n");
	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
