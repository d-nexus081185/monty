#include "monty.h"
/**
 * multiplication_function - multiply two values in a stack
 * @stack: a stack pointer
 * @line_number: a line number
 */
void multiplication_function(stack_t **stack, unsigned int line_number)
{
	int num = 0;
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack_function(stack);
		free_array_function();
		fclose(mont->file);
		free(mont);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->next->n;
	num *= (*stack)->n;
	(*stack)->next->n = num;
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (*stack)
		(*stack)->prev = NULL;
}
