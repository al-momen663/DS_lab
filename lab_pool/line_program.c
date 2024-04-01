#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

// Structure to represent a line of text
struct Line
{
	char content[MAX_LINE_LENGTH];
};

// Stack structure for undo and redo
struct Stack
{
	struct Line data[MAX_LINES];
	int top;
};

// Initialize an empty stack
void initializeStack(struct Stack *stack)
{
	stack->top = -1;
}

void push(struct Stack *stack, const char *content)
{
	if (stack->top < MAX_LINES - 1)
	{
		strcpy(stack->data[++stack->top].content, content);
	}
	else
	{
		printf("Stack overflow! Cannot add more lines.\n");
	}
}

const char *pop(struct Stack *stack)
{
	if (stack->top >= 0)
	{
		return stack->data[stack->top--].content;
	}
	else
	{
		printf("Stack is empty! No lines to undo.\n");
		return NULL;
	}
}

void bubbleSort(struct Line lines[], int numLines)
{
	for (int i = 0; i < numLines - 1; ++i)
	{
		for (int j = 0; j < numLines - i - 1; ++j)
		{
			if (strcmp(lines[j].content, lines[j + 1].content) > 0)
			{
				// Swap lines
				struct Line temp = lines[j];
				lines[j] = lines[j + 1];
				lines[j + 1] = temp;
			}
		}
	}
}

int main()
{
	struct Stack undoStack, redoStack;
	initializeStack(&undoStack);
	initializeStack(&redoStack);

	struct Line lines[MAX_LINES];
	int numLines = 0;

	printf("Enter lines of text (type 'end' to finish):\n");
	char input[MAX_LINE_LENGTH];
	while (1)
	{
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; // Remove newline character

		if (strcmp(input, "end") == 0)
		{
			break;
		}

		push(&undoStack, input);
		strcpy(lines[numLines++].content, input);
	}

	bubbleSort(lines, numLines);

	printf("\nSorted lines (ascending order):\n");
	for (int i = 0; i < numLines; ++i)
	{
		printf("%s\n", lines[i].content);
	}

	const char *undoneLine = pop(&undoStack);
	if (undoneLine)
	{
		printf("\nUndone line: %s\n", undoneLine);
	}

	return 0;
}
