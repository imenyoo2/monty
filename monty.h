#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

void free_stack(stack_t *stack);


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*func_t)(stack_t **stack, unsigned int line_number);

/* opcodes functions */

/* TODO: more then 5 functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

instruction_t *parse(int line_number, char *line);
extern int NODE_DATA;
extern int IS_VALID;

char *get_opcode(char *line);
void set_operand(char *str);
int _strcmp(char *src, char *dst);


/* utils */

/* error functions */
void check_malloc(void *ptr);
void unknown_inst_error(char *opcode, int line_number);
void usage(int line_number, int id);
#define MAIN_USAGE 0
#define PUSH_USAGE 1
#define PINT_USAGE 2
void cant_open_file(char *file);

#endif
