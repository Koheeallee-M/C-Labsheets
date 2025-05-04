#include <stdio.h>
#include <math.h>

int poly(int x){
 return (pow(x,4) + pow(x,3) + (3 * pow(x,2))+ 2 );
}

int main(){
int val;

printf("Enter a value\n");
scanf("%d", &val);

printf("Your number is: %d", poly(val));
}
