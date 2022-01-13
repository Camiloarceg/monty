#include "monty.h"
/**
 * mapcomand - map the opcode with the functions
 * @buffer: the line from de .m
 * @line_numb: line number.
 * @stack: the head of the list.
 * @fileptr: file descriptor.
 *
 * Return:void
 */
void mapcomand(char *buffer, unsigned int line_numb,
		stack_t **stack, FILE *fileptr)
{
	instruction_t modulo[] = {{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"div", divic}, {"mul", mul}, {"mod", mod},
		{"rotl", rotl}, {"pstr", pstr}, {"#", nop}, {"pchar", pchar},
		{"rotr", rotr}, {"stack", fstack}, {"queue", queue}, {NULL, NULL}};
	char *instruction = NULL, *zero;
	int i = 0, flag = 0;

	variables.number = 0, instruction = strtok(buffer, " \t\n");
	if (instruction == NULL || instruction[0] == '#')
		return;
	if (strcmp(instruction, "push") == 0)
	{
		zero = strtok('\0', " \t\n");
		if (!zero)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_numb);
			free(buffer), free_list(*stack), fclose(fileptr), exit(EXIT_FAILURE);
		}
		if (_isdigit(zero) == 1)
			variables.number = atoi(zero);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_numb);
			free(buffer), free_list(*stack), fclose(fileptr), exit(EXIT_FAILURE);
		}
	}
	for (i = 0; modulo[i].f != NULL; i++)
	{
		if (strcmp(modulo[i].opcode, instruction) == 0)
		{
			modulo[i].f(stack, line_numb);
			flag = 1;
		}
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_numb, instruction);
		free(buffer), free_list(*stack), fclose(fileptr), exit(EXIT_FAILURE);
	}
}
/**
 * _isdigit - check if it is digit
 * @digit: digit
 *
 * Return: 0 or 1
 */
int _isdigit(char *digit)
{
	int i;

	for (i = 0; digit[i] != '\0'; i++)
	{
		if ((digit[i] < 48 || digit[i] > 57) && digit[0] != 45)
		{
			return (0);
		}
	}
	return (1);
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
