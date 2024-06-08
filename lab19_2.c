#include <stdio.h>

int main()
{
	int c, minimum, maximum, middle, n, search, array[100], binary_count = 0, linear_count = 0;
	int found_linear = 0, found_binary = 0;

	printf("Enter number of elements\n");
	scanf("%d", &n);

	printf("Enter %d integers\n", n);

	for (c = 0; c < n; c++)
		scanf("%d", &array[c]);

	printf("Enter value to find\n");
	scanf("%d", &search);

	// Linear search
	for (int i = 0; i < n; i++)
	{
		linear_count++;
		if (array[i] == search)
		{ // Fixed the comparison operator
			found_linear = 1;
			break;
		}
	}

	// Binary search
	minimum = 0;
	maximum = n - 1;

	while (minimum <= maximum)
	{
		binary_count++;
		middle = (minimum + maximum) / 2;

		if (array[middle] < search)
		{
			minimum = middle + 1;
		}
		else if (array[middle] == search)
		{
			found_binary = 1;
			printf("%d found at location %d (binary search).\n", search, middle + 1);
			break;
		}
		else
		{
			maximum = middle - 1;
		}
	}

	if (!found_binary)
		printf("Not found! %d isn't present in the list (binary search).\n", search);

	if (found_linear)
	{
		printf("%d found at location %d (linear search).\n", search, linear_count);
	}
	else
	{
		printf("Not found! %d isn't present in the list (linear search).\n", search);
	}

	if (linear_count > binary_count)
	{
		printf("Linear search time is greater\n");
	}
	else if (binary_count > linear_count)
	{
		printf("Binary search time is greater\n");
	}
	else
	{
		printf("Both are equal\n");
	}

	return 0;
}
