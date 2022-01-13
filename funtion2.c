#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the given node
 * @line_numb: line number
 * Return: returns nothing
 */
void add(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_numb);
		exit(EXIT_FAILURE);
	}
	tmp->next->n += tmp->n;
	pop(stack, line_numb);
}
/**
 * nop - doesn’t do anything.
 * @stack: struct stack_t
 * @line_number: line number to show in error case
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub - subtracts the top element of the stack
 *           from the second top element of the stack
 * @stack: pointer to the given node
 * @ln: line nunber
 * Return: returns nothing
 */
void sub(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_numb);
		exit(EXIT_FAILURE);
	}
	tmp->next->n -= tmp->n;
	pop(stack, line_numb);
}
