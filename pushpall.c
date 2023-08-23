#include "monty.h"

/**
 * push - adds to top of the stack
 * @stk: top of the stack
 * @linet_number: the token line number
 * return: void
 */
void push(stack_t **stk, unsigned int linet_number)
{
	stack_t *new;

	if (stk == NULL)
	{
		fprintf(stderr, "L%d: unknown stack\n", linet_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stk(stk, linet_number);
		exit(EXIT_FAILURE);
	}
	new->n = variables.temp;
	new->prev = NULL;
	new->next = *stk;

	if (*stk != NULL)
		(*stk)->prev = new;
	*stk = new;
}


/**
 * pall - function that prints the stack
 * @stk: the top of the stack
 * @linet_number: the line number
 *
 * return: void
 */
void pall(stack_t **stk, unsigned int linet_number)
{
	stack_t *print;
	(void)linet_number;

	print = *stk;
	while (print != NULL)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}

