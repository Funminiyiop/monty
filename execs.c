#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @cnter: line_counter
* @file: poiner to monty file
* @cntt: line content
* Return: no return
*/
int execute(char *cntt, stack_t **stack, unsigned int cnter, FILE *file)
{
	instruction_t opst[] = {
		{"push", push2Stack}, {"pall", pallStack}, {"pint", pintStack},
		{"pop", popStack}, {"swap", swapSck}, {"add", addStack},
		{"nop", f_nop}, {"sub", subtStack}, {"div", divStack},
		{"mul", multStack}, {"mod", modeStack}, {"pchar", prntChar},
		{"pstr", f_pstr}, {"rotl", f_rotl}, {"rotr", f_rotr},
		{"queue", f_queue}, {"stack", fomatStack}, {NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(cntt, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, cnter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", cnter, op);
		fclose(file);
		free(cntt);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

