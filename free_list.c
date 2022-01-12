#include "monty.h"
/**
 * free_dlistint - free the list
 * @stack: list
 *
 */
void free_list(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp);
	}
}
