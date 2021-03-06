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
 * sub - subtracts the top element of the stack
 *           from the second top element of the stack
 * @stack: pointer to the given node
 * @line_numb: line nunber
 * Return: returns nothing
 */
void sub(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_numb);
		exit(EXIT_FAILURE);
	}
	tmp->next->n -= tmp->n;
	pop(stack, line_numb);
}
/**
 * divic - divides the second top element of the stack by
 *          the top element of the stack
 * @stack: pointer to the given node
 * @line_numb: line number
 * Return: returns nothing
 */
void divic(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_numb);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_numb);
		exit(EXIT_FAILURE);
	}
	tmp->next->n /= tmp->n;
	pop(stack, line_numb);
}

/**
 * mul - mul the top two elements of the stack
 * @stack: pointer to the given node
 * @line_numb: line number
 * Return: returns nothing
 */
void mul(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_numb);
		exit(EXIT_FAILURE);
	}
	tmp->next->n *= tmp->n;
	pop(stack, line_numb);
}
/**
 * mod - mod the top two elements of the stack
 * @stack: pointer to the given node
 * @line_numb: line number
 * Return: returns nothing
 */
void mod(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_numb);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_numb);
		exit(EXIT_FAILURE);
	}
	tmp->next->n %= tmp->n;
	pop(stack, line_numb);
}
