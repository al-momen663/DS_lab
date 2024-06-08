#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	char search;
	int found = 0;

	printf("Enter number of characters\n");
	scanf("%d", &n);

	char array[n];

	printf("Enter %d characters\n", n);
	for (int c = 0; c < n; c++)
	{
		scanf(" %c", &array[c]);
	}

	printf("Enter character to find\n");
	scanf(" %c", &search);

	// Sort the array using qsort from stdlib.h

	qsort(array, n, sizeof(char), (int (*)(const void *, const void *))strcmp);

	// Binary search
	int minimum = 0;
	int maximum = n - 1;
	int middle;

	while (minimum <= maximum)
	{
		middle = (minimum + maximum) / 2;

		if (array[middle] < search)
		{
			minimum = middle + 1;
		}
		else if (array[middle] == search)
		{
			found = 1;
			break;
		}
		else
		{
			maximum = middle - 1;
		}
	}

	if (found)
	{
		printf("%c found at location %d (in sorted array).\n", search, middle + 1);
	}
	else
	{
		printf("Not found! %c isn't present in the list.\n", search);
	}

	return 0;
}
