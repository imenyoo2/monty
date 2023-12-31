#include "monty.h"


/**
 * check_malloc - checks if malloc call successfull
 * @ptr: result of malloc call
 * Return: void
 */
int check_malloc(void *ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		EXIT_STATUS = EXIT_FAILURE;
		return (1);
	}
	return (0);
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
/**
 * unknown_inst_error - print unknown instruction error
 * @opcode: the uncorrect opcode
 * @line_number: current line number
 * Return: void
 */
void unknown_inst_error(char *opcode, int line_number)
{
	int i = 0;

	while (opcode[i] != ' ' && opcode[i])
		i++;
	opcode[i] = '\0';
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	EXIT_STATUS = EXIT_FAILURE;
}


/* TODO: maybe this shouldn't be stderr */
/**
 * usage - print usage
 * @line_number: current line number
 * @id: specify which usage to print
 * Return: void
 */
void usage(int line_number, enum usage_enum id)
{
	if (id == MAIN_USAGE)
		fprintf(stderr, "USAGE: monty file\n");
	else if (id == PUSH_USAGE)
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
	else if (id == PINT_USAGE)
		fprintf(stderr, "L%d: usage: pint\n", line_number);
	EXIT_STATUS = EXIT_FAILURE;
}

/**
 * print_error - print specific error
 * @line_number: current line number
 * @error: specify which error to print
 * Return: void
 */
void print_error(int line_number, enum error_enum error)
{
	if (error == PINT_STACK_EMPTY)
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	else if (error == PCHAR_STACK_EMPTY)
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	else if (error == POP_STACK_EMPTY)
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	else if (error == SWAP_STACK_SHORT)
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	else if (error == ADD_STACK_SHORT)
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	else if (error == SUB_STACK_SHORT)
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	else if (error == DIV_STACK_SHORT)
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	else if (error == MUL_STACK_SHORT)
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	else if (error == MOD_STACK_SHORT)
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	else if (error == DIV_BY_ZERO)
		fprintf(stderr, "L%d: division by zero\n", line_number);
	else if (error == PCHAR_OUT_RANGE)
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	EXIT_STATUS = EXIT_FAILURE;
}

/**
 * cant_open_file - print can't open file error
 * @file: file that can't be opened
 * Return: void
 */
void cant_open_file(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
