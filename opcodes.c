#include "monty.h"

/**
 * push - pushes an item to the top of stack
 * @n: integer to be pushed
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!IS_VALID)
		usage(line_number, PUSH_USAGE);
	new = malloc(sizeof(stack_t));
	check_malloc(new);
	new->n = NODE_DATA;
	/* pushing the first element to the stack */
	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		new->next = NULL;
		new->prev = *stack;
		*stack = new;
	}
	EXIT_STATUS = 0;
}

/**
 * pall - print all values on the stack starting from the top
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number; /* TODO: change this to use when error */

	while(tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
	EXIT_STATUS = 0;
}

void pint(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		print_error(line_number, PINT_STACK_EMPTY);
		return;
	}
	printf("%d\n", (*stack)->n);
}


void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *buffer = *stack;

	if (*stack == NULL)
	{
		print_error(line_number, POP_STACK_EMPTY);
		return;
	}

	*stack = buffer->prev;
	free(buffer);
	EXIT_STATUS = 0;
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *buffer;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		print_error(line_number, SWAP_STACK_SHORT);
		return;
	}

	buffer = (*stack)->prev;
	(*stack)->next = buffer;
	buffer->next = NULL;
	(*stack)->prev = buffer->prev;
	buffer->prev = *stack;
	*stack = buffer;

	EXIT_STATUS = 0;
}

void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		print_error(line_number, ADD_STACK_SHORT);
		return;
	}

	result = (*stack)->n;
	result += (*stack)->prev->n;
	pop(stack, line_number);
	(*stack)->n = result;
	EXIT_STATUS = 0;
}

void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		print_error(line_number, SUB_STACK_SHORT);
		return;
	}

	result = (*stack)->n;
	result = (*stack)->prev->n - result;
	pop(stack, line_number);
	(*stack)->n = result;
	EXIT_STATUS = 0;
}

void div_(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		print_error(line_number, DIV_STACK_SHORT);
		return;
	}

	result = (*stack)->n;
	if (result == 0)
	{
		print_error(line_number, DIV_BY_ZERO);
		return;
	}
	result = (*stack)->prev->n / result;
	pop(stack, line_number);
	(*stack)->n = result;
	EXIT_STATUS = 0;
}


void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		print_error(line_number, MUL_STACK_SHORT);
		return;
	}

	result = (*stack)->n;
	result *= (*stack)->prev->n;
	pop(stack, line_number);
	(*stack)->n = result;
	EXIT_STATUS = 0;
}

void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		print_error(line_number, MOD_STACK_SHORT);
		return;
	}

	result = (*stack)->n;
	if (result == 0)
	{
		print_error(line_number, DIV_BY_ZERO);
		return;
	}
	result = (*stack)->prev->n % result;
	pop(stack, line_number);
	(*stack)->n = result;
	EXIT_STATUS = 0;
}


void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	EXIT_STATUS = 0;
}
