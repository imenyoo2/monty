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
void pstr(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

instruction_t *parse(int line_number, char *line);
extern int NODE_DATA;
extern int IS_VALID;
extern int EXIT_STATUS;
extern int EXIT_STATUS;

char *get_opcode(char *line);
void set_operand(char *str);
int _strcmp(char *src, char *dst);


/* utils */

/* error functions */
int check_malloc(void *ptr);
void unknown_inst_error(char *opcode, int line_number);

enum usage_enum {MAIN_USAGE, PUSH_USAGE, PINT_USAGE};
void usage(int line_number, enum usage_enum id);

enum error_enum {PINT_STACK_EMPTY, PCHAR_STACK_EMPTY, POP_STACK_EMPTY, SWAP_STACK_SHORT, ADD_STACK_SHORT, SUB_STACK_SHORT, DIV_STACK_SHORT, DIV_BY_ZERO, MUL_STACK_SHORT, MOD_STACK_SHORT, PCHAR_OUT_RANGE};
void print_error(int line_number, enum error_enum error);

void cant_open_file(char *file);

#endif
