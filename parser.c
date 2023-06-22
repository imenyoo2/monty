#include "monty.h"


/**
 * parse - parse line
 * @line: line to be parsed
 * Return: instruction_t
 */
instruction_t *parse(char *line)
{
	instruction_t *result = NULL;
	char *opcodes[] = {"push", "pall"};
	func_t functions[] = {&push, &pall};
	int i;
	char *buffer;

	char *opcode = get_opcode(line);
	for (i = 0; i < 2; i++)
	{
		if (_strcmp(opcode, opcodes[i]))
		{
			result = malloc(sizeof(instruction_t));
			check_malloc(result);
			result->f = functions[i];
			buffer = malloc(strlen(opcodes[i]));
			check_malloc(buffer);
			strcpy(buffer, opcodes[i]);
			result->opcode = buffer;
		}
	}
	if (result)
	{
		set_operand(opcode);
	}
	return (result);
}

char *get_opcode(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] != ' ')
			return (&line[i]);
		i++;
	}
	return (NULL);
}

/**
 * _strcmp - compair first bytes of src with dst
 * @src: long string
 * @dst: short string
 * Return: 1 if equal, 0 otherwize
 */
int _strcmp(char *src, char *dst)
{
	int i = 0;

	while (src[i] && dst[i])
	{
		if (src[i] != dst[i])
			return (0);
		i++;
	}
	return (1);
}


int NODE_DATA = 0;

/**
 * set_operand - obtains the operand from str and sets the global variable
 * @str: pointer the the opcode
 * Return: void
 */
void set_operand(char *str)
{
	int operand;
	int i = 0;
	char *buffer;

	while (str[i] != ' ')
		i++;
	/* preparing for int conversion */
	operand = strtol(&str[i], &buffer, 10);
	/* TODO: check buffer */
	NODE_DATA = operand;
	(void) NODE_DATA;
}
