#include "monty.h"
/**
 * free_array_function - free all memory allocated
 */
void free_array_function(void)
{
	int i = 0;

	for (; mont->arr[i] != NULL; i++)
		free(mont->arr[i]);
	free(mont->arr);
	mont->arr = NULL;
}

