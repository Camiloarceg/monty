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

/**
 * add_end - adds a new node at the end of a dlistint_t list.
 * @stack: head of the list.
 */
void add_end(stack_t **stack)
{
	stack_t *new_node, *tmp = *stack;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new_node->n = variables.number;
		*stack = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		new_node->n = variables.number;
		tmp->next = new_node;
		new_node->prev = tmp;
		new_node->next = NULL;
	}
}
