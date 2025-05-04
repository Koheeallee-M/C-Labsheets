/*Write a program to input the radius of a sphere and output the volume and surface area of the sphere in C*/

#include <stdio.h>
#include <math.h>

int main(){
	float radius, volume, surfaceArea;
	const float PI = 3.14159;

	printf("Enter the radius of a sphere: ");
	scanf("%f", &radius);

	volume = (4.0/3.0) * PI * pow(radius, 3);
	surfaceArea = 4 * PI * pow(radius, 2);

	printf("Volume of the sphere: %.2f\n", volume);
	printf("Surface area of the sphere: %.2f\n", surfaceArea);

	return 0;
}

