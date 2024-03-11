#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int array[MAX_SIZE];
    int size, position, num1, num2;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the position to insert numbers (0 to %d): ", size);
    scanf("%d", &position);

    printf("Enter the first number to insert: ");
    scanf("%d", &num1);
    printf("Enter the second number to insert: ");
    scanf("%d", &num2);

    if (position < 0 || position > size) {
        printf("Invalid position. Insertion failed.\n");
    } else {
        for (int i = size; i > position; i--) {
            array[i] = array[i - 1];
        }
        array[position] = num1;
        array[position + 1] = num2;

        size += 2;
        printf("Array after insertion:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    return 0;
}
