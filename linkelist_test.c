#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *ptr;
};
typedef struct node NODE;

int main()
{
	NODE *head, *first, *temp = NULL;
	int count = 0;
	int choice = 1;
	first = NULL;

	while (choice)
	{
		head = (NODE *)malloc(sizeof(NODE));
		printf("memory we get = %p\n", (void *)head);
		printf("Enter a data element to insert into the Linked List\n");
		scanf("%d", &head->num);
		head->ptr = NULL;

		if (first != NULL)
		{
			temp->ptr = head;
			temp = head;
		}
		else
		{
			first = head;
			temp = head;
		}

		printf("Do you want to continue(Type 0 to exit or any integer to continue)?\n");
		scanf("%d", &choice);
	}

	// Display the status of the linked list
	temp = first;
	printf("\nStatus of the linked list is\n");
	while (temp != NULL)
	{
		printf("[%p]   [%d] -> ", (void *)temp, temp->num);
		count++;
		temp = temp->ptr;
	}
	printf("[NULL]\n");
	printf("No. of nodes in the list = %d\n", count);

	// Insertion
	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	printf("Enter the position where you want to insert the new node\n");
	int pos;
	scanf("%d", &pos);
	printf("Enter the number for the new node\n");
	scanf("%d", &(newNode->num));

	// Reset temp to the beginning
	temp = first;
	NODE *prev = NULL;

	// Traverse to the position before where we want to insert
	for (int i = 0; temp != NULL && i < pos; ++i)
	{
		prev = temp;
		temp = temp->ptr;
	}

	// Insert the new node
	if (prev == NULL)
	{ // Insert at the beginning
		newNode->ptr = first;
		first = newNode;
	}
	else if (temp == NULL)
	{ // Insert at the end
		prev->ptr = newNode;
		newNode->ptr = NULL;
	}
	else
	{ // Insert in the middle
		newNode->ptr = temp;
		prev->ptr = newNode;
	}

	// Display the status of the linked list after insertion
	temp = first;
	printf("\nStatus of the linked list after insertion is\n");
	while (temp != NULL)
	{
		printf("[%p]   [%d] -> ", (void *)temp, temp->num);
		temp = temp->ptr;
	}
	printf("[NULL]\n");

	// Free the allocated memory
	temp = first;
	while (temp != NULL)
	{
		NODE *next = temp->ptr;
		free(temp);
		temp = next;
	}

	return 0;
}
