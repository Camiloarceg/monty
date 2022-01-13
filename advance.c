#include "monty.h"
/**
 * @brief 
 * 
 */
void pchar(stack_t **stack, unsigned int line_numb)
{
    stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_numb);
		exit(EXIT_FAILURE);
	}
	if (tmp->n >= 33 && tmp->n <=126)
    {
        fprintf(stdout, "%c\n", tmp->n);
    }
    else
    {
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_numb);
		exit(EXIT_FAILURE);
	}
}
