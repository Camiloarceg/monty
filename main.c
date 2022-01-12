#include "monty.h"
#include <stdio.h>
/**
 * main - file
 * @argc: data
 * @argv: data
 * Return: 0
 *
 */
int main(int argc, char *argv[])
{
	FILE *fileptr;
	char *buffer = NULL;
	unsigned int line_numb = 0;
	size_t len = 0;
	stack_t *stack = NULL;
	int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fileptr = fopen(argv[1], "r");
	while (getline(&buffer, &len, fileptr) != -1)
	{
		line_numb += 1;
		if (buffer == NULL)
			break;
		for (i = 0; buffer[i] != '\0'; ++i)
		{
			if (buffer[i] != ' ' && buffer[i] != '\t')
				break;
		}
		mapcomand(buffer, line_numb, &stack, fileptr);
		free(buffer);
		buffer = NULL;
	}
	free_list(stack);
	free(buffer);
	fclose(fileptr);
	return (0);
}
