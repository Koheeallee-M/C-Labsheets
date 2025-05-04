/*Polynomial function using pow()*/

#include <stdio.h>
#include <math.h>

int poly(int x){
	int result = (pow(x,4) + pow(x,3) + (3*(pow(x,2))) + 2);

	return result;
}

int main(){
	
	int x = 0;
	printf("Enter an integer: ");
	scanf("%d", &x);
	printf("The result is: %d\n", poly(x));
	return 0;
}
