#include <stdio.h>

#define ARRAY_SIZE 10

int main()
{
    int array[ARRAY_SIZE];
    int size;
    int num1, num2;
    int pos1, pos2;
    int i, j;
    printf("Enter the size of the array (max %d): ", ARRAY_SIZE);
    scanf("%d", &size);

    // Check for array overflow
    if (size >= ARRAY_SIZE)
    {
        printf("Array size exceeds maximum limit. Exiting...\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    // Input first number and position
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the position to insert the first number (0 to %d): ", ARRAY_SIZE - 1);
    scanf("%d", &pos1);
    if (pos1 >= 0 && pos1 < ARRAY_SIZE)
    {
        for (i = ARRAY_SIZE - 1; i > pos1; i--)
        {
            array[i] = array[i - 1];
        }
        array[pos1] = num1;
    }
    else
    {
        printf("Invalid position for the first number. Exiting...\n");
        return 1;
    }

    // Input second number and position
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the position to insert the second number (0 to %d): ", ARRAY_SIZE - 1);
    scanf("%d", &pos2);

    // Insert first number

    // Insert second number
    if (pos2 >= 0 && pos2 < ARRAY_SIZE)
    {
        for (j = ARRAY_SIZE - 1; j > pos2; j--)
        {
            array[j] = array[j - 1];
        }
        array[pos2] = num2;
    }
    else
    {
        printf("Invalid position for the second number. Exiting...\n");
        return 1;
    }

    // Display the array
    printf("Array after insertion:\n");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
