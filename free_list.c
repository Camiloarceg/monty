#include "monty.h"
/**
 * free_list - free the list
 * @stack: list
 *
 * Return: void
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
