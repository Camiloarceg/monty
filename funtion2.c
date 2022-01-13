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
