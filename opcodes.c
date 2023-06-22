#include "monty.h"

/**
 * push - pushes an item to the top of stack
 * @stack: head of stack
 * @line_number: current line number
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
		(*stack)->next = new;
		*stack = new;
	}
	EXIT_STATUS = 0;
}

/**
 * pall - print all values on the stack starting from the top
 * @stack: head of the stack
 * @line_number: current line number
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


/**
 * pstr - print all stack as ascii
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number; /* TODO: change this to use when error */

	while(tmp)
	{
		if (tmp->n < 0x40 || tmp->n > 0x7f)
			break;
		putchar(tmp->n);
		tmp = tmp->prev;
	}
	putchar('\n');
	EXIT_STATUS = 0;
}


/**
 * pint - print all stack data
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		print_error(line_number, PINT_STACK_EMPTY);
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pchar - print the top of stack as int
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		print_error(line_number, PCHAR_STACK_EMPTY);
		return;
	}
	if ((*stack)->n < 0x40 || (*stack)->n > 0x7f)
	{
		print_error(line_number, PCHAR_OUT_RANGE);
		return;
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pop - delete the top of the stack
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
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

/**
 * swap - swap the top two items
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
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

/**
 * add - adds the top two items
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
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

/**
 * sub - substitute the top two items
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
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

/**
 * div_ - devide the top two items
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
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


/**
 * mul - multiply the top two items
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
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

/**
 * mod - modulate the top two items
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
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

/**
 * rotl - move the top item to bottom
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *first = *stack;
	(void) line_number;

	if (last == NULL || last->prev == NULL)
		return;
	while (first->prev)
		first = first->prev;

	*stack = last->prev;
	last->prev->next = NULL;
	first->prev = last;
	last->prev = NULL;
	last->next = first;
}

/**
 * rotr - move the bottom item to top
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *first = *stack;
	(void) line_number;

	if (last == NULL || last->prev == NULL)
		return;
	while (first->prev)
		first = first->prev;

	first->next->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;

	*stack = first;
}

/**
 * nop - does nothing
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	EXIT_STATUS = 0;
}
