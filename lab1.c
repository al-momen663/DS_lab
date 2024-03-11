#include <stdio.h>
int main() {
	int array1[10];
	int n, i;

	printf("Enter the value of n: ");
	scanf("%d", &n);
	if(n <= 10){
	for (i = 0; i < n; i++){
		//printf("Enter the value of array index %d: ", i);
		scanf("%d", &array1[i]);
	}
	printf("The value of the arrays with %d items: ", n);
	for (i = 0; i < n; i++){
		
		printf("%d", array1[i]);
	}
	printf("\n");
	

	
	}
	
	else{
		printf("Enter the value of n between 1 to 10\n");
	}
	return 0;

	
}