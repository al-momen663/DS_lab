#include <stdio.h>

int main()
{
	int array[] = {1, 2, 3, 4, 5, 3, 3, 7, 8, 3}; // Example array
	int size = sizeof(array) / sizeof(array[0]);
	int element;
	int count = 0;

	// Asking user to input the element to be searched
	printf("Enter the element to be searched: ");
	scanf("%d", &element);

	// Loop through the array to count occurrences
	for (int i = 0; i < size; i++)
	{
		if (array[i] == element)
		{
			count++;
		}
	}

	// Check if the element was found
	if (count > 0)
	{
		printf("Element %d is present %d times.\n", element, count);
	}
	else
	{
		printf("Element not found.\n");
	}

	return 0;
}
