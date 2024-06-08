#include <stdio.h>
int binarySearch(int array[], int x, int low, int high)
{

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (array[mid] == x)
			return mid;

		if (array[mid] < x)
			low = mid + 1;

		else
			high = mid - 1;
	}

	return -1;
}

int main()
{
	int array[100], n, c, d, swap;

	printf("Enter number of elements\n");
	scanf("%d", &n);

	printf("Enter %d integers\n", n);

	for (c = 0; c < n; c++)
		scanf("%d", &array[c]);

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
		printf("%d\n", array[c]);
	int search;
	printf("Enter the element which you want to search:");
	scanf("%d", &search);

	int result = binarySearch(array, search, 0, n - 1);
	if (result == -1)
		printf("Not found");
	else
		printf("Element is found at index %d", result);

	return 0;
}