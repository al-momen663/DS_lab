#include <stdio.h>
#include <stdlib.h>

struct node
{
	int roll;
	struct node *left, *right;
};
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->roll = item;
	temp->left = temp->right = NULL;
	return temp;
};
struct node *insert_roll(struct node *node, int roll)
{

	if (node == NULL)
		return newNode(roll);

	if (roll < node->roll)
		node->left = insert_roll(node->left, roll);
	else if (roll > node->roll)
		node->right = insert_roll(node->right, roll);

	return node;
}
void print_in_preorder(struct node *root)
{
	if (root)
	{
		printf("%d\t", root->roll);
		print_in_preorder(root->left);
		print_in_preorder(root->right);
	}
	// printf("\n");
}
void search_roll(struct node *root, int roll)
{
	if (root == NULL)
	{
		printf("Roll number not found");
		return;
	}

	if (root->roll == roll)
	{
		printf("Roll number found");
		return;
	}

	if (root->roll < roll)
		search_roll(root->right, roll);
	else
		search_roll(root->left, roll);
}

int main()
{
	int roll_number;
	struct node *root = NULL;
	int flag = 1;

	while (flag == 1)
	{
		printf("Insert a roll number (for exit enter 0): ");
		scanf("%d", &roll_number);
		if (roll_number == 0)
		{
			flag = 0;
			printf("\n");
			break;
		}

		if (root == NULL)
		{
			root = insert_roll(root, roll_number);
		}
		else
		{
			insert_roll(root, roll_number);
		}
	}

	printf("Inserted roll are: ");
	print_in_preorder(root);
	printf("Enter the roll number you wanna search:  ");
	scanf("%d", &roll_number);
	search_roll(root, roll_number);

	return 0;
}