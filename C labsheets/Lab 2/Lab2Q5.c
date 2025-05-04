#include <stdio.h>

void inputArray(int A[], int n){
	for(int i = 0; i < n; i++){
	printf("Input number %d", i+1);
	printf("\n");
	scanf("%d", &A[i]);
	}
}

void displayArray(int A[], int n){
	for(int i = 0; i < n; i++){
	printf("The value of %d: is %d\n", i, A[i]);
	}
}

int main(){
	int n, d;
	
	printf("Enter the number of elements\n");
	scanf("%d", &n);

	int A[n];
	inputArray(A, n);
	
	printf("Enter number of elements to display\n");
	scanf("%d", &d);

	displayArray(A, d);
}
