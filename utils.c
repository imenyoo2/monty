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
		puts("USAGE: monty file");
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
