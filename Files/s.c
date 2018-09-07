/*#include<stdio.h>
struct stack
{
	int top;
	int capacity;
	char *cmd;
};
int main()
{
	int i=0;
struct stack s;
s.top=0;
s.capacity=20;
s.cmd=(char *)malloc(capacity * sizeof());
s.ptr[0]=23;
s.ptr[1]=21;
s.ptr[2]=20;
s.ptr[3]=19;
while(i<=3)
	{
		printf("%d\n",s.ptr[i]);
		i++;
	}	
	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Type for individual stack entry
 */
struct stack_entry {
  char *data;
  struct stack_entry *next;
};

/**
 * Type for stack instance
 */
struct stack_t
{
  struct stack_entry *head;
  size_t stackSize;  // not strictly necessary, but
                     // useful for logging
};

/**
 * Create a new stack instance
 */
struct stack_t *newStack(void)
{
  struct stack_t *stack = malloc(sizeof *stack);
  if (stack)
  {
    stack->head = NULL;
    stack->stackSize = 0;
  }
  return stack;
};

/**
 * Make a copy of the string to be stored (assumes  
 * strdup() or similar functionality is not
 * available
 */
char *copyString(char *str)
{
  char *tmp = malloc(strlen(str) + 1);
  if (tmp)
    strcpy(tmp, str);
  return tmp;
}

/**
 * Push a value onto the stack
 */
void push(struct stack_t *theStack, char *value)
{
  struct stack_entry *entry = malloc(sizeof *entry); 
  if (entry)
  {
    entry->data = copyString(value);
    entry->next = theStack->head;
    theStack->head = entry;
    theStack->stackSize++;
  }
  else
  {
    // handle error here
  }
}

void show(struct stack_t *theStack)
{
	printf("%d\n",theStack->stackSize);

	while(theStack->stackSize>0)
	{
	  if (theStack->head != NULL)
	  {
	    struct stack_entry *tmp = theStack->head;
	    theStack->head = theStack->head->next;
	    printf("%s\n",tmp->data);
	    theStack->stackSize--;
	  }
	}
}
/**
 * Get the value at the top of the stack
 */
char *top(struct stack_t *theStack)
{
  if (theStack && theStack->head)
    return theStack->head->data;
  else
    return NULL;
}

/**
 * Pop the top element from the stack; this deletes both 
 * the stack entry and the string it points to
 */
void pop(struct stack_t *theStack)
{
  if (theStack->head != NULL)
  {
    struct stack_entry *tmp = theStack->head;
    theStack->head = theStack->head->next;
    free(tmp->data);
    free(tmp);
    theStack->stackSize--;
  }
}

/**
 * Clear all elements from the stack
 */
void clear (struct stack_t *theStack)
{
  while (theStack->head != NULL)
    pop(theStack);
}

/**
 * Destroy a stack instance
 */
void destroyStack(struct stack_t **theStack)
{
  clear(*theStack);
  free(*theStack);
  *theStack = NULL;
}
int main(void)
{
  struct stack_t *theStack = newStack();
  char *data;

  push(theStack, "foo");
  push(theStack, "bar");

  data = top(theStack);
  printf("%s",data);
  pop(theStack);
 // clear(theStack);
  //destroyStack(&theStack);
}