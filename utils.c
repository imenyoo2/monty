#include "main.h"


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
