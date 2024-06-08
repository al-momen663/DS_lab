
#include <stdio.h>

int main()
{
	int n, i, j, delete1, delete2;
	int found1 = 0, found2 = 0;

	printf("Enter number of elements\n");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("Underflow: Array is empty\n");
		return 1;
	}

	int array[n];
	printf("Enter %d integers\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	printf("Enter first number to delete\n");
	scanf("%d", &delete1);

	for (i = 0; i < n; i++)
	{
		if (array[i] == delete1)
		{
			found1 = 1;
			for (j = i; j < n - 1; j++)
			{
				array[j] = array[j + 1];
			}
			n--;
			break;
		}
	}

	if (!found1)
	{
		printf("Underflow: %d not found in the array\n", delete1);
		return 1;
	}

	if (n <= 0)
	{
		printf("Underflow: Array is empty after deleting %d\n", delete1);
		return 1;
	}

	printf("Enter second number to delete\n");
	scanf("%d", &delete2);

	for (i = 0; i < n; i++)
	{
		if (array[i] == delete2)
		{
			found2 = 1;
			for (j = i; j < n - 1; j++)
			{
				array[j] = array[j + 1];
			}
			n--;
			break;
		}
	}

	if (!found2)
	{
		printf("Underflow: %d not found in the array\n", delete2);
		return 1;
	}

	printf("Array after deletions:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
