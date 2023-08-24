#include "monty.h"

/**
 * free_stk - frees the stack
 * @stk: the stack.
 * @line_number: the line number.
 *
 * return: void.
 */
void free_stk(stack_t **stk, unsigned int linet_number)
{
	if (stk == NULL)
		return;
	while (*stk != NULL)
		pop(stk, linet_number);
}
