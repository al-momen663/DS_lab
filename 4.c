#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char name[10];
	char course[10];
	int ID;
	struct node *ptr;
};

int main()
{
	struct node *head = NULL;
	struct node *second = NULL;
	struct node *third = NULL;
	struct node *fourth = NULL;
	struct node *fifth = NULL;

	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));
	fourth = (struct node *)malloc(sizeof(struct node));
	fifth = (struct node *)malloc(sizeof(struct node));

	// Enter the student data for each node
	head->ID = 101;
	strcpy(head->name, "Momen");
	strcpy(head->course, "Computer Science");

	second->ID = 102;
	strcpy(second->name, "shad");
	strcpy(second->course, "Mathematics");

	third->ID = 103;
	strcpy(third->name, "nirob");
	strcpy(third->course, "Physics");

	fourth->ID = 104;
	strcpy(fourth->name, "akash");
	strcpy(fourth->course, "Chemistry");

	// Link the nodes
	head->ptr = second;
	second->ptr = third;
	third->ptr = fourth;
	fourth->ptr = fifth;
	fifth->ptr = NULL;
	struct node *current = head;
	while (current != NULL)
	{
		printf("ID: %d\n", current->ID);
		printf("Name: %s\n", current->name);
		printf("Course: %s\n", current->course);
		printf("\n");
		current = current->ptr;
	}
	return 0;
}