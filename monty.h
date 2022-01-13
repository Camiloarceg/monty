#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#define UNUSED(x) (void)(x)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

int number;

void _free_double_pointer(char **d_pointer);
void mapcomand(char *buffer, unsigned int line_numb,
		stack_t **stack, FILE *fileptr);
void push(stack_t **stack, unsigned int line_numb);
void pall(stack_t **stack, unsigned int line_numb);
void free_list(stack_t *stack);
void pint(stack_t **stack, unsigned int line_numb);
void pop(stack_t **stack, unsigned int line_numb);
void swap(stack_t **stack, unsigned int ln);
void add(stack_t **stack, unsigned int line_numb);
int _isdigit(char *digit);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_numb);
void divic(stack_t **stack, unsigned int line_numb);
void mul(stack_t **stack, unsigned int line_numb);
void mod(stack_t **stack, unsigned int line_numb);
void pchar(stack_t **stack, unsigned int line_numb);
void pstr(stack_t **stack, unsigned int line_numb);
void rotl(stack_t **stack, unsigned int line_numb);

#endif /* MAIN_H */
