#include "monty.h"

/**
 * push - pushes an item to the top of stack
 * @n: integer to be pushed
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void) line_number;

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
}

/**
 * pall - print all values on the stack starting from the top
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	while(tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}
