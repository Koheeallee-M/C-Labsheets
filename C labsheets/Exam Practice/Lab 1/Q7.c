/*Even numbers*/

#include <stdio.h>
#include <math.h>

int main(){
	int even, sum = 0;
	int count = 0;

	even = 0;

	while(even !=-1){
		printf("Enter a number, you will be prompted until you input -1: ");
		scanf("%d",&even);
		if(even % 2 == 0){
		count++;
		sum = sum + even;
		}
	
	}

	printf("Total number of even numbers input: %d\n", count);
	printf("Sum of even numbers: %d\n", sum);

}
