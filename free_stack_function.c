#include "monty.h"
/**
 * free_stack_function - free stack
 * @stack: a struct node pointer
 */
void free_stack_function(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		temp = NULL;
	}
}

