#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact
{
	char name[50];
	char phone[15];
};

struct Contact phoneDirectory[MAX_CONTACTS];
int numContacts = 0;

void insertContact()
{
	if (numContacts >= MAX_CONTACTS)
	{
		printf("Phone directory is full. Cannot add more contacts.\n");
		return;
	}

	printf("Enter contact name: ");
	scanf("%s", phoneDirectory[numContacts].name);
	printf("Enter phone number: ");
	scanf("%s", phoneDirectory[numContacts].phone);

	numContacts++;
	printf("Contact added successfully!\n");
}

void deleteContact()
{
	char searchName[50];
	printf("Enter the name of the contact to delete: ");
	scanf("%s", searchName);

	int found = 0;
	for (int i = 0; i < numContacts; i++)
	{
		if (strcmp(phoneDirectory[i].name, searchName) == 0)
		{
			for (int j = i; j < numContacts - 1; j++)
			{
				phoneDirectory[j] = phoneDirectory[j + 1];
			}
			numContacts--;
			found = 1;
			printf("Contact deleted successfully!\n");
			break;
		}
	}

	if (!found)
	{
		printf("Contact not found.\n");
	}
}

void linearSearch()
{
	char searchName[50];
	printf("Enter the name of the contact to search: ");
	scanf("%s", searchName);

	for (int i = 0; i < numContacts; i++)
	{
		if (strcmp(phoneDirectory[i].name, searchName) == 0)
		{
			printf("Contact found! Name: %s, Phone: %s\n", phoneDirectory[i].name, phoneDirectory[i].phone);
			return;
		}
	}

	printf("Contact not found.\n");
}

void binarySearch()
{
	printf("Binary search not implemented in this example.\n");
}

int main()
{
	int choice;
	while (1)
	{
		printf("\nPhone Directory Menu:\n");
		printf("1. Insert new contact\n");
		printf("2. Delete contact\n");
		printf("3. Search contact (linear search)\n");
		printf("4. Search contact (binary search)\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insertContact();
			break;
		case 2:
			deleteContact();
			break;
		case 3:
			linearSearch();
			break;
		case 4:
			binarySearch();
			break;
		case 5:
			printf("Exiting. Have a nice day!\n");
			return 0;
		default:
			printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}
