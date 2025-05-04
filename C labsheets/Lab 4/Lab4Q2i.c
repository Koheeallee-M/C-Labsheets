#include <stdio.h>

int Power(int x, int n){
if(n == 0){
return 1;
}
else{
return x * Power(x, n-1);
}
}

int main()
{
int x;
int n;

printf("Enter an integer: ");
scanf("%d", &x);
printf("Enter an exponent: ");
scanf("%d", &n);

printf("The result is: %d\n", Power(x,n));
return 0;
}
