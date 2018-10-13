


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
    printf("History service unavalable ");
  }
}
/*
NOt need of this function

void show(struct stack_t *theStack,char max[])
{
	int count,j=0;
	struct stack_t *theStack1 = newStack();
	theStack1->head=theStack->head;
    count=atoi(max);
	if(theStack->stackSize<=count)
		{
			count=theStack->stackSize-3;
		}
	while(j!=count)
	{
	  if (theStack->head != NULL)
	  {
	    struct stack_entry *tmp = theStack->head;
	    theStack->head = theStack->head->next;
	    printf("%s\n",tmp->data);
	  	j++;
	  }

	}
	theStack->head=theStack1->head;
}
*/
void ShowAll(struct stack_t *theStack)
{
	
	struct stack_t *theStack1 = newStack();
	theStack1->head=theStack->head;
	
	while (theStack->head != NULL)
    {
    	 struct stack_entry *tmp = theStack->head;
    	 theStack->head = theStack->head->next;
	     printf("%s\n",tmp->data);
    }
	theStack->head=theStack1->head;
	struct stack_entry *tmp = theStack->head;
}

/**
 * Get the value at the top of the stack
 */
 int CheckNULL(struct stack_t *theStack)
 {
  if (theStack->head == NULL)
  {return 1;}
  else
    {return 0;}
 }
char *top(struct stack_t *theStack)
{

  if (theStack && theStack->head)
    return theStack->head->data;
  else
    return NULL;
}

char *catchdata(struct stack_t *theStack)
{
  if (theStack->head != NULL)
  {
    struct stack_entry *tmp = theStack->head;
    theStack->head = theStack->head->next;
    return theStack->head->data;
    //free(tmp->data);
    //free(tmp);
    //theStack->stackSize--;
  }
  else
  {
     struct stack_entry *tmp = "empty";
     //theStack->head = theStack->head->next;
    return tmp;
  }
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
void RemoveAll (struct stack_t *theStack)
{
  while (theStack->head != NULL)
    pop(theStack);
  printf("clear history\n");
}

/**
 * Destroy a stack instance
 */
void destroyStack(struct stack_t **theStack)
{
  RemoveAll(*theStack);
  free(*theStack);
  *theStack = NULL;
}


/*
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
}*/