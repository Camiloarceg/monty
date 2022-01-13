#include "monty.h"
/**
 * pchar - print char
 * @stack: list
 * @line_numb: number of line
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
	if (tmp->n >= 33 && tmp->n <= 126)
	{
		fprintf(stdout, "%c\n", tmp->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_numb);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the top of the stack,
 *		 followed by a new line.
 * @stack: list.
 * @line_numb: number of line.
 *
 */
void pstr(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	(void) line_numb;

	tmp = *stack;
	if (tmp == NULL)
	{
		fprintf(stdout, "\n");
		return;
	}
	while (tmp != NULL)
	{
		if (tmp->n >= 33 && tmp->n <= 126)
		{
			fprintf(stdout, "%c", tmp->n);
		}
		else
			break;
		tmp = tmp->next;
	}
	fprintf(stdout, "\n");
}

/**
 * rotl - rotates the stack to the top.
 * @stack: list.
 * @line_numb: number of line.
 *
 */
void rotl(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	(void) line_numb;
	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*stack)->next->prev = NULL;
	tmp->next = *stack;
	tmp->next->prev = tmp;
	(*stack) = (*stack)->next;
	tmp->next->next = NULL;
}

/**
 * rotr - revert stack
 * @stack: stack
 * @line_numb: number line
 *
 */
void rotr(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp = *stack;

	(void) line_numb;
	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*stack = tmp;
	(*stack)->next->prev = *stack;
}
