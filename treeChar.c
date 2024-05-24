#include <stdio.h>
#include <stdlib.h>

struct node
{
	char key;
	struct node *left, *right;
};

struct node *newNode(char item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%c \n", root->key);
		inorder(root->right);
	}
}

void print_preorder(struct node *root)
{
	if (root)
	{
		printf("%c\n", root->key);
		print_preorder(root->left);
		print_preorder(root->right);
	}
}

void print_postorder(struct node *root)
{
	if (root)
	{
		print_postorder(root->left);
		print_postorder(root->right);
		printf("%c\n", root->key); // Changed %d to %c
	}
}

struct node *insert(struct node *node, char key)
{

	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

int main()
{

	struct node *root = NULL;
	root = insert(root, 'F');
	insert(root, 'B');
	insert(root, 'A');
	insert(root, 'D');
	insert(root, 'C');
	insert(root, 'E');
	insert(root, 'G');
	insert(root, 'I');
	insert(root, 'H');

	printf("\n\n\nPre Order\n");
	print_preorder(root);
	printf("Inorder\n");
	inorder(root);
	printf("\n\n\n Post Order\n");
	print_postorder(root);

	return 0;
}
