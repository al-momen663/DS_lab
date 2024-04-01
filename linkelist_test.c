#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node
{
	int data1;
	int data2;
	struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data1, int data2)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newNode->data1 = data1;
	newNode->data2 = data2;
	newNode->next = NULL;
	return newNode;
}

// Function to count nodes in the linked list
int countNodes(struct Node *head)
{
	int count = 0;
	struct Node *current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

int main()
{
	// Create nodes
	struct Node *head = createNode(1, 10);
	struct Node *second = createNode(2, 20);
	struct Node *third = createNode(3, 30);

	// Link nodes
	head->next = second;
	second->next = third;

	// Count nodes
	int nodeCount = countNodes(head);
	printf("Number of nodes in the linked list: %d\n", nodeCount);

	return 0;
}