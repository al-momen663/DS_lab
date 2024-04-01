#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

// Program to create a simple linked list with 3 nodes
int main()
{
	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;

	// allocate 3 nodes in the heap
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));

	head->data = 10;	 // assign data in first node
	head->next = second; // Link first node with the second node
	// assign data to second node
	second->data = 20;
	// Link second node with the third node
	second->next = third;
	third->data = 30;	// assign data to third node
	third->next = NULL; // End of Linked list

	// Print the linked list
	printf("Start = %d\n", head);
	printf("Data in Start = %d\n", head->data);
	printf("Pointer in first Node = %d\n", head->next);
	printf("Second = %d\n", second);
	printf("Data in Second Node = %d\n", second->data);
	printf("Pointer in Second Node = %d\n", second->next);
	printf("Third = %d\n", third);
	printf("Data in Third Node = %d\n", third->data);
	printf("Pointer in Third Node = %d\n", third->next);

	printf("[%d]   [%d][%d]   [%d][%d]   [%d][%d]\n", head, head->data, head->next, second->data, second->next, third->data, third->next);

	return 0;
}