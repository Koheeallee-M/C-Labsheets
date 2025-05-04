#include <stdio.h>

void findminmax(int A[], int n, int *max, int *min){
	*max = A[0];
	*min = A[0];

	for(int i = 1; i < n; i++){
		if (A[i] > *max){			
			*max = A[i];
		}
		else if(A[i] < *min){
			*min = A[i];
		}
	}
}

int main(){
	int n, max, min;
	
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int A[n];

	printf("Enter %d elements:\n", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}

	findminmax(A, n, &max, &min);

	printf("Maximum value: %d\n", max);
	printf("Minimum value: %d\n", min);

	return 0;
}
