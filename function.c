#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: pointer to the given node
 * @line_numb: value of the element to insert to the node
 * Return: returns nothing
 */
void push(stack_t **stack, unsigned int line_numb)
{
	stack_t *new_node = NULL;

	UNUSED(line_numb);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new_node->n = number;
		*stack = new_node;
		(*stack)->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		new_node->n = number;
		(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->prev = NULL;
		*stack = new_node;
	}
}
/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the given node
 * @line_numb: line number
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_numb)
{
	stack_t *h;
	(void)line_numb;

	h = *stack;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to the given node
 * @line_numb: line number
 * Return: returns nothing
 */
void pint(stack_t **stack, unsigned int line_numb)
{
	UNUSED(line_numb);

	if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_numb);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack
 * @stack: pointer to the given stack
 * @line_numb: line number
 * Return: returns nothing
 */
void pop(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_numb);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the given node
 * @line_numb: line number
 * Return: returns nothing
 */
void swap(stack_t **stack, unsigned int line_numb)
{
	int i, num;
	stack_t *tmp;

	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		++i;
	}
	if (i < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_numb);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}
