#include <stdio.h>
int main()
{
	int c, minimum, maximum, middle, n, search, array[100], binary_count = 0, linear_count = 0;

	printf("Enter number of elements\n");
	scanf("%d", &n);

	printf("Enter %d integers\n", n);

	for (c = 0; c < n; c++)
		scanf("%d", &array[c]);

	printf("Enter value to find\n");
	scanf("%d", &search);

	for (int i = 0; i < n; i++)
	{
		linear_count++;
		if (array[i] = search)
		{
			break;
		}
	}

	minimum = 0;
	maximum = n - 1;
	middle = (minimum + maximum) / 2;

	while (minimum <= maximum)
	{
		binary_count++;

		if (array[middle] > search)
			minimum = middle + 1;

		else if (array[middle] == search)
		{
			printf("%d found at location %d.\n", search, middle + 1);
			break;
		}
		else
			maximum = middle - 1;

		middle = (minimum + maximum) / 2;
	}
	if (minimum > maximum)
		printf("Not found! %d isn't present in the list.\n", search);

	if (linear_count > binary_count)
	{
		printf("lenear search time is greater\n");
	}
	else if (binary_count > linear_count)
	{
		printf("binary search greater");
	}
	else
		printf("Both equal");

	return 0;
}