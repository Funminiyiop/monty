#include "monty.h"

/**
* pallStack - prints all values from top of stack.
* @head: stack head
* @counter: no used
* Return: void
*/
void pallStack(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}


/**
* pintStack - prints the value at the top of stack
* @head: stack head
* @counter: line_number
* Return: void
*/
void pintStack(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


/**
* popStack - removes top element of stack.
* @head: stack head
* @counter: line_number
* Return: void
*/
void popStack(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}


/**
* f_nop- does nothing
* @head: stack head
* @counter: line_number
* Return: void
*/
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

