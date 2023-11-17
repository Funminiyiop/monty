#include "monty.h"

/**
* f_rotl- rotates stack to top
* @head: stack head
* @counter: line_number
* Return: void
*/
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmpry = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmpry->next != NULL)
	{
		tmpry = tmpry->next;
	}
	tmpry->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmpry;
	(*head) = aux;
}


/**
* f_rotr- rotates stack to bottom
* @head: stack head
* @counter: line_number
* Return: void
*/
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}


/**
* fomatStack -  sets format of data to stack (LIFO).
* @head: stack head
* @counter: line_number
* Return: void
*/
void fomatStack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}


/**
* swapSck -  swaps top two elements of the stack
* @head: stack head
* @counter: line_number
* Return: void
*/
void swapSck(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
