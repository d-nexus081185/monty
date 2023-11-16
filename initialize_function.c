#include "monty.h"
/**
 * initialize_function - initialize parameters of param structure
 */
void initialize_function(void)
{
	mont = malloc(sizeof(param));
	if (!mont)
		malloc_error();
	mont->n = 0;
	mont->line_number = 1;
	mont->arr = NULL;
	mont->entry = 0;
	mont->read_len = 0;
}

