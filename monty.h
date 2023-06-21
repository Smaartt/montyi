#ifndef __MONTY_H
#define __MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define __local __attribute__((weak))
#define __silent __attribute__((unused))
#define FAIL (exit(EXIT_FAILURE))
#define PASS (exit(EXIT_SUCCESS))
#define FAIL_ARGNUM (fprintf(stderr, "USAGE: monty file\n"), FAIL)
#define FAIL_FILE(x) (fprintf(stderr, "Error: Can't open file %s\n", x), FAIL)
#define FAIL_OPCODE(x, y) \
	(fprintf(stderr, "L%d: unknown instruction %s\n", x, y), free(y), FAIL)
#define FAIL_MALLOC (fprintf(stderr, "Error: malloc failed\n"), FAIL)
#define fi if
#define esle else
#define new_struct struct

typedef unsigned int uint;

/**
 * enum modes - the eeeeeeeeeeeeoperation modes
 * @STACK: the stack mode
 * @QUEUE: the queue mode
 */
enum modes
{
	STACK,
	QUEUE
};
/**
 * struct state_s - the state variable
 * @delim: the delim
 * @token: the token
 * @fp: the file pointer
 * @line: the file line
 * @mode: the operation mode
 */
typedef struct state_s
{
	char *token;
	char *delim;
	FILE *fp;
	char *line;
	int mode;
} state_t;

/**
 * struct stack_s - the doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: it points to the previous element of the stack (or queue)
 * @next: it points to the next element of the stack (or queue)
 *
 * Description: the doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - the opcode and its function
 * @opcode: the opcodee
 * @f: the function to handle the opcode
 *
 * Description: the opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

state_t s = {
	NULL,
	"\n\t\a\r ;:",
	NULL,
	NULL,
	STACK
};


/**
 * len - it print doubly linked list
 * @h: the list
 * Return: the number of nodes
 */
__local size_t len(const stack_t *h)
{
	size_t nodes = 0;

	for (; h; nodes++)
		h = h->next;

	return (nodes);
}

/**
 * is_number - it iterates each character of string to check of isdigit
 * @n: the integer
 * Return: returns 0 if is number, else -1 if not
 */
__local int is_number(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
		return (-1);
	}
	return (0);
}

#endif
