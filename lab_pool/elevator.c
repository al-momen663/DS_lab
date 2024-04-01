#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

struct Stack
{
	int data[MAX_FLOORS];
	int top;
};

void initializeStack(struct Stack *stack)
{
	stack->top = -1;
}

void push(struct Stack *stack, int floor)
{
	if (stack->top < MAX_FLOORS - 1)
	{
		stack->data[++stack->top] = floor;
	}
	else
	{
		printf("Stack overflow! Cannot add more requests.\n");
	}
}

int pop(struct Stack *stack)
{
	if (stack->top >= 0)
	{
		return stack->data[stack->top--];
	}
	else
	{
		printf("Stack is empty! No requests to process.\n");
		return -1;
	}
}

int main()
{
	int currentFloor = 0;
	struct Stack requests;
	initializeStack(&requests);

	push(&requests, 5);
	push(&requests, 2);
	push(&requests, 8);

	while (requests.top >= 0)
	{
		int nextFloor = pop(&requests);
		if (nextFloor >= 0 && nextFloor < MAX_FLOORS)
		{
			printf("Moving from floor %d to floor %d\n", currentFloor, nextFloor);
			currentFloor = nextFloor;
		}
		else
		{
			printf("Invalid floor request. Skipping.\n");
		}
	}

	printf("Elevator reached its final destination.\n");
	return 0;
}
