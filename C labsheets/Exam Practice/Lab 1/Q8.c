/* Check prime*/

#include <stdio.h>
#include <stdbool.h>

int main(){
	int n, i;
	bool isPrime = true;


	printf("Enter a positive integer: ");
	scanf("%d", &n);

	if(n <= 0){
		printf("Invalid input. Please enter a positive integer.\n");
		return 1;
	}

	if(n == 1){
		isPrime =  false;
	} else{
		for (int i = 2; i<= n/2; i ++){
			if(n % i == 0){
				isPrime = false;
				break;
			}
		}
	}

	if(isPrime){
		printf("%d is a prime number. \n", n);
	}
	else{
		printf("%d is not a prime number.\n", n);
	}

	return 0;
}
