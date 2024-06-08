#include <stdio.h>

int binarySearch(char array[], char search, int low, int high)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (array[mid] == search)
			return mid;

		if (array[mid] < search)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int main()
{
	int n, c, d;
	char array[100], swap;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter %d characters: \n", n);
	for (c = 0; c < n; c++)
		scanf(" %c", &array[c]);

	for (c = 0; c < n - 1; c++)
	{
		for (d = 0; d < n - c - 1; d++)
		{
			if (array[d] > array[d + 1])
			{
				swap = array[d];
				array[d] = array[d + 1];
				array[d + 1] = swap;
			}
		}
	}

	printf("Sorted list in ascending order:\n");
	for (c = 0; c < n; c++)
		printf("%c ", array[c]);

	char search;
	printf("\nEnter the element you want to search: ");
	scanf(" %c", &search);

	int result = binarySearch(array, search, 0, n - 1);
	if (result == -1)
		printf("Element not found\n");
	else
		printf("Element found at index %d\n", result);

	return 0;
}