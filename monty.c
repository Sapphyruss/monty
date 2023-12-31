#define _GNU_SOURCE
#include "monty.h"
#include "stdio.h"

/**
 * main - primary function with two arguments
 * @argc: count limit to input
 * @argv: filename
 *
 * Description: open file from argv[1] and get opcodes from file
 * return: success
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *filename, *buf = NULL;
	size_t bufsize = 0;
	char *input;
	stack_t *stk = NULL;
	unsigned int linet_number = 0;

	filename = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&buf, &bufsize, fp) != -1)
	{
		input = strtok(buf, "\n");
		tokenizer(input, &stk, linet_number);
		linet_number++;
	}
	fclose(fp);
	free(buf);
	if (stk != NULL)
		free_stk(&stk, linet_number);
	return (EXIT_SUCCESS);
}
