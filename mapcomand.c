#include "monty.h"
/**
 * @brief
 *
 */
void mapcomand(char *buffer, unsigned int line_numb, stack_t **stack, FILE *fileptr)
{
	instruction_t modulo[] = {{"push", push}, {"pall", pall}, {"pint", pint},
	{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", NULL}, {NULL, NULL}};
	char *instruction = NULL;
	char *zero;
	int i = 0;

	number = 0;
	instruction = strtok(buffer, " \t\n");
	if (strcmp(instruction, "push") == 0)
	{
		zero = strtok('\0', " \t\n");
		if (!zero)
		{
			fprintf(stderr, "L<%d>: usage: push integer\n", line_numb);
			free(buffer);
			free_list(*stack);
			fclose(fileptr);
			exit(EXIT_FAILURE);
		}
		if (zero[0] >= '0' && zero[0] <= '9')
		{
			number = atoi(zero);
			printf("number: %d\n", number);
		}
		else
		{
			fprintf(stderr, "L<%d>: usage: push integer\n", line_numb);
			free(buffer);
			free_list(*stack);
			fclose(fileptr);
			exit(EXIT_FAILURE);
		}
	}
	for (i = 0; modulo[i].f != NULL; i++)
	{
		if (strcmp(modulo[i].opcode, instruction) == 0)
		{
			modulo[i].f(stack, line_numb);
		}
	}
}
