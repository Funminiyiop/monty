#include "monty.h"

/**
* push2Stack - pushes an element to stack
* @head: stack head
* @counter: line_number
* Return: void
*/
void push2Stack(stack_t **head, unsigned int counter)
{
	int n;

	if (bus.arg)
	{
		checkFlagging(head, counter);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}



/**
* checkFlagging - pushes an element to stack
* @head: stack head
* @counter: line_number
* Return: void
*/
void checkFlagging(stack_t **head, unsigned int counter)
{
	int j = 0, flag = 0;

	if (bus.arg[0] == '-')
		j++;
	for (; bus.arg[j] != '\0'; j++)
	{
		if (bus.arg[j] > 57 || bus.arg[j] < 48)
			flag = 1; }
	if (flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}
