#define _GNU_SOURCE
#include "main.h"

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: arguments array
 * Return: 0 if success, otherwise exit
 */
int main(int argc, char **argv)
{
	FILE *source;
	char *line = NULL;
	ssize_t read;
	size_t len;
	int line_number = 0;
	instruction_t *instruction;
	stack_t *stack_pointer = NULL; /* initializing the stack */
	(void) stack_pointer;

	if (argc != 2)
	{
		puts("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	source = fopen(argv[1], "r");
	if (source == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, source)) != -1)
	{
		line_number++;
		instruction = parse(line);
    instruction->f(&stack_pointer, line_number);
	}
	fclose(source);
	if (line)
	{
		free(line);
	}
	return (0);
}

/* TODO: L<line_number>: unknown instruction <opcode> + EXIT_FAILURE */
/* TODO: Error: malloc failed + EXIT_FAILURE */
