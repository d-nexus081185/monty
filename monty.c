#include "monty.h"
param *mont;
/**
 * main - Monty byte cocde compiler
 * @argc: argument counter
 * @argv: argument vector
 * Return: an integer value 1 onerror otherwise 0;
 */
int main(int argc, char *argv[])
{
	stack_t *head;
	char *file_name = argv[1];
	void (*opcmd)(stack_t**, unsigned int);

	head = NULL;
	initialize_function();
	if (argc != 2)
		print_error_message("USAGE: monty file", NULL);
	read_file(file_name);
	while (fgets(mont->buffer, BUF_SIZE, mont->file) != NULL)
	{
		remove_newline();
		if (mont->read_len == 0)
		{
			mont->line_number += 1;
			continue;
		}
		tokenizer(mont->buffer, mont->read_len);
		if (mont->arr[0] == 0 || mont->arr[0][0] == '#')
		{
			mont->line_number += 1;
			free_array_function();
			continue;
		}
		opcmd = get_dispatch_function(mont->arr[0]);
		if (opcmd == NULL)
		{
			print_line_number(mont->line_number);
			free_array_function();
			free_all_mem(&head);
			exit(EXIT_FAILURE);
		}
		opcmd(&head, mont->line_number);
		mont->line_number += 1;
		mont->n = 0;
		free_array_function();
	}
	free_all_mem(&head);
	return (0);
}


/**
 * free_all_mem - free all memory after usage
 * @stack: a stack list
 */
void free_all_mem(stack_t **stack)
{
	free_stack_function(stack);
	fclose(mont->file);
	free(mont);
}

/**
 * read_file - read file
 * @file_name: name of file to read
 */
void read_file(char *file_name)
{
	mont->file = fopen(file_name, "r");
	if (!mont->file)
		print_error_message("Error: Can't open file ", file_name);
}

/**
 * remove_newline - replace all newline with null terminator
 */
void remove_newline(void)
{
	int len;

	len = strlen(mont->buffer);
	if (mont->buffer[len - 1] == '\n')
	{
		mont->buffer[len - 1] = '\0';
		len--;
	}
	mont->read_len = len;
}
