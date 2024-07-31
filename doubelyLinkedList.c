#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node
{
	char data;
	struct Node *next;
	struct Node *prev;
} Node;

int main()
{
	int n;
	char ch;

	// Ask the user for the number of nodes
	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	// Initialize the head and tail pointers
	Node *head = NULL;
	Node *tail = NULL;

	// Create the doubly linked list using a loop
	for (int i = 0; i < n; i++)
	{
		// Allocate memory for a new node
		Node *newNode = (Node *)malloc(sizeof(Node));
		if (!newNode)
		{
			printf("Memory allocation failed\n");
			return 1;
		}

		// Ask the user for the data for this node
		printf("Enter character for node %d: ", i + 1);
		scanf(" %c", &newNode->data); // Note the space before %c to consume any leftover newline character

		// Initialize the new node's pointers
		newNode->next = NULL;
		newNode->prev = tail;

		// If the list is empty, make this node the head
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			// Otherwise, link the new node to the previous node
			tail->next = newNode;
		}

		// Update the tail pointer to the new node
		tail = newNode;
	}

	// Insert a new element at the last position
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (!newNode)
	{
		printf("Memory allocation failed\n");
		return 1;
	}

	printf("Enter character for the new last node: ");
	scanf(" %c", &newNode->data);

	newNode->next = NULL;
	newNode->prev = tail;

	if (tail)
	{
		tail->next = newNode;
	}
	tail = newNode;

	// If the list was empty initially, make this new node the head
	if (head == NULL)
	{
		head = newNode;
	}

	// Print the elements of the doubly linked list
	printf("Elements in the doubly linked list are: ");
	Node *current = head;
	while (current != NULL)
	{
		printf("%c ", current->data);
		current = current->next;
	}
	printf("\n");

	return 0;
}
