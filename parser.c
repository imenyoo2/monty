#include "monty.h"


/**
 * parse - parse line
 * @line: line to be parsed
 * Return: instruction_t
 */
instruction_t *parse(int line_number, char *line)
{
	instruction_t *result = NULL;
	char *opcodes[] = {"push", "pall", "pint", "pop", "swap", "add"};
	func_t functions[] = {&push, &pall, &pint, &pop, &swap, &add};
	int i;
	char *buffer = NULL;

	char *opcode = get_opcode(line);
	if (!opcode)
		return (NULL);
	for (i = 0; i < 6; i++)
	{
		if (_strcmp(opcode, opcodes[i]))
		{
			result = malloc(sizeof(instruction_t));
			check_malloc(result);
			result->f = functions[i];
			buffer = malloc(strlen(opcodes[i]) + 1);
			check_malloc(buffer);
			strcpy(buffer, opcodes[i]);
			result->opcode = buffer;
		}
	}
	if (!result)
		unknown_inst_error(opcode, line_number);
	set_operand(opcode);
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
int IS_VALID = 1;

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

	if (!str || *str == '\n')
		IS_VALID = 0;
	else
		IS_VALID = 1;
	while (str[i] != ' ' && str[i])
		i++;
	/* preparing for int conversion */
	operand = strtol(&str[i], &buffer, 10);
	/* check buffer */
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ' && buffer[i] != '\n')
			IS_VALID = 0;
	}
	NODE_DATA = operand;
}
