#define _GNU_SOURCE
#include "monty.h"

int EXIT_STATUS = 0;

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: arguments array
 * Return: 0 if success, otherwise exit
 */
int main(int argc, char **argv)
{
	FILE *source = NULL;
	char *line = NULL;
	ssize_t read = 0;
	size_t len = 0;
	int line_number = 0;
	instruction_t *instruction = NULL;
	stack_t *stack_pointer = NULL; /* initializing the stack */

	if (argc != 2)
		usage(line_number, MAIN_USAGE);
	source = fopen(argv[1], "r");
	if (source == NULL)
		cant_open_file(argv[1]);

	while ((read = getline(&line, &len, source)) != -1)
	{
		line_number++;
		instruction = parse(line_number, line);
		if (!instruction)
			continue;
		instruction->f(&stack_pointer, line_number);
		free(instruction->opcode);
		free(instruction);
		if (EXIT_STATUS)
			break;
	}
	fclose(source);
	if (line)
	{
		free(line);
		free_stack(stack_pointer);
		if (EXIT_STATUS)
			exit(EXIT_STATUS);
	}
	return (0);
}
