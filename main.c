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
	ssize_t nread = 0;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fileptr = fopen(argv[1], "r");
	if (fileptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&buffer, &len, fileptr)) != -1)
	{
		line_numb += 1;
		if (nread <= 2)
			continue;
		if (buffer == NULL)
			continue;
		mapcomand(buffer, line_numb, &stack, fileptr);
		free(buffer);
		buffer = NULL;
	}
	free_list(stack);
	free(buffer);
	fclose(fileptr);
	return (0);
}
