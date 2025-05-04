#include <stdio.h>
#include <math.h>
int main()
{
int inp;
int count = 0;
int sum = 0;

do{
printf("Input a number: \n");
scanf("%d", &inp);
if(inp%2 == 0){
count = count + 1;
sum = sum + inp;
}
}
while(inp != -1);

printf("Number of even numbers: %d \n", count);
printf("Sum of even numbers: %d \n", sum);
return 0;
}
