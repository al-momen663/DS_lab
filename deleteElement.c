#include <stdio.h>

#define MAX_SIZE 100
int deleteElement(int arr[], int *size, int element) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] == element) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            i--;
        }
    }
    return found;
}

int main() {
    int arr[MAX_SIZE];
    int size, element1, element2;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the first element to delete: ");
    scanf("%d", &element1);
    printf("Enter the second element to delete: ");
    scanf("%d", &element2);
    if (deleteElement(arr, &size, element1)) {
        printf("%d deleted successfully.\n", element1);
    } else {
        printf("This element (%d) cannot be deleted as it does not exist.\n", element1);
    }
    if (deleteElement(arr, &size, element2)) {
        printf("%d deleted successfully.\n", element2);
    } else {
        printf("This element (%d) cannot be deleted as it does not exist.\n", element2);
    }
    printf("Updated array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
