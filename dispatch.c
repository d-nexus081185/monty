#include "monty.h"
/**
 * get_dispatch_function - get the corresponding function
 * @str: opcommand
 * Return: found command index
 */
void (*get_dispatch_function(char *str))(stack_t**, unsigned int)
{
	int i = 0;
	instruction_t func[] = {
		{"add", print_add}, {"pall", pall_stack_function},
		{"push", push_stack}, {"pint", print_int},
		{"queue", find_entry}, {"stack", find_entry},
		{"pop", pop_function}, {"nop", nop},
		{"swap", swap}, {"div", divide_function},
		{"sub", sub}, {"mod", print_mod},
		{"mul", multiplication_function}, {"pchar", pchar},
		{"pstr", paste_string_function}, {"rotl", rotate_stack_function},
		{"rotr", rotate_stack_function}, {NULL, NULL}
	};

	while (func[i].opcode != NULL)
	{
		if (strcmp(func[i].opcode, str) == 0)
			return (func[i].f);
		i++;
	}
	return (NULL);
}
