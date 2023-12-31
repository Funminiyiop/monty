#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
* struct stack_s - doubly linked list representation
*	of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct bus_s - variables -args, file, line content
* @arg: value
* @file: pointer to monty file
* @content: line content
* @lifi: flag change stack <-> queue
* Description: carries values through the program
*/
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
int execute(char *cntt, stack_t **stack, unsigned int cnter, FILE *file);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);

/* Monty Functions */
void push2Stack(stack_t **head, unsigned int counter);
void pallStack(stack_t **head, unsigned int counter);
void pintStack(stack_t **head, unsigned int counter);
void popStack(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void fomatStack(stack_t **head, unsigned int counter);
void swapSck(stack_t **head, unsigned int counter);

/* Math Functions */
void addStack(stack_t **head, unsigned int cnter);
void divStack(stack_t **head, unsigned int counter);
void multStack(stack_t **head, unsigned int counter);
void subtStack(stack_t **head, unsigned int counter);
void modeStack(stack_t **head, unsigned int counter);

/* Utility Functions */
void prntChar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void addnode(stack_t **head, int n);
void free_stack(stack_t *head);

void checkFlagging(stack_t **head, unsigned int counter);

#endif

