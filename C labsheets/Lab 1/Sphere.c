#include <stdio.h>
#include <math.h>
int main()
{
float rad, vol, tsa;
printf("Please input a radius\n");
scanf("%f", &rad);
vol = (4.0/3.0) * M_PI * pow(rad, 3);
tsa = 4 * M_PI * pow(rad, 2);

printf("The volume is %f\n", vol);
printf("The total surface area is %f\n", tsa);

return 0;
}
