#include "monty.h"


/**
 * check_malloc - checks if malloc call successfull
 * @ptr: result of malloc call
 * Return: void
 */
void check_malloc(void *ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}


/**
 * free_stack - frees the stack
 * @stack: the head of stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *buffer;

	if (stack)
		buffer = stack->prev;
	free(stack);
	while (buffer)
	{
		stack = buffer;
		buffer = stack->prev;
		free(stack);
	}
}

/* TODO: move these files to errors.c */
void unknown_inst_error(char *opcode, int line_number)
{
	int i = 0;

	while (opcode[i] != ' ' && opcode[i])
		i++;
	opcode[i] = '\0';
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}


/* TODO: maybe this shouldn't be stderr */
void usage(int line_number, int id)
{
	if (id == 0)
		fprintf(stderr, "USAGE: monty file\n");
	else if (id == 1)
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

void cant_open_file(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
