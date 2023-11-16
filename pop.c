#include "monty.h"
/**
 * pop_function - a function that delete on a stack
 * @stack: a struct node pointer
 * @line: number of lines counted
 */
void pop_function(stack_t **stack, unsigned int line)
{

	stack_t *next_val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_stack_function(stack);
		exit(EXIT_FAILURE);
	}
	next_val = (*stack)->next;
	free(*stack);
	*stack = next_val;
	if (*stack)
		(*stack)->prev = NULL;
}

