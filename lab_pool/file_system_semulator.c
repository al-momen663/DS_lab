#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 50

struct File
{
	char name[MAX_FILENAME];
};

struct Stack
{
	struct File data[MAX_FILES];
	int top;
};

void initializeStack(struct Stack *stack)
{
	stack->top = -1;
}

void push(struct Stack *stack, const char *filename)
{
	if (stack->top < MAX_FILES - 1)
	{
		strcpy(stack->data[++stack->top].name, filename);
	}
	else
	{
		printf("Stack overflow! Cannot navigate further.\n");
	}
}

const char *pop(struct Stack *stack)
{
	if (stack->top >= 0)
	{
		return stack->data[stack->top--].name;
	}
	else
	{
		printf("Stack is empty! Cannot go back.\n");
		return NULL;
	}
}

int main()
{
	struct Stack navigationStack;
	initializeStack(&navigationStack);

	printf("Creating directory 'Documents'\n");
	push(&navigationStack, "Documents");

	printf("Creating file 'report.txt'\n");
	push(&navigationStack, "report.txt");

	const char *poppedFile = pop(&navigationStack);
	if (poppedFile)
	{
		printf("Navigated back from '%s'\n", poppedFile);
	}

	printf("Deleting file 'report.txt'\n");

	return 0;
}
