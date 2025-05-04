#include <stdio.h>
#include <math.h>

#define PI 3.14159623

void sphere_area_volume(double radius, double *surface_area, double *volume){
	*surface_area = 4 * PI * radius * radius;
	*volume = (4.0 / 3.0) * PI * radius * radius * radius;
	
}
int main(){
	double small_rad, large_rad, small_TSA, large_TSA, small_volume, large_volume;
	printf("Enter the radius of the small ball: ");
	scanf("%lf", &small_rad);
	printf("Enter the outer radius: ");
	scanf("%lf", &large_rad);

	sphere_area_volume(small_rad, &small_TSA, &small_volume);
	sphere_area_volume(large_rad, &large_TSA, &large_volume);

	double liquid_vol = large_volume - small_volume;
	double liquid_touch = small_TSA + large_TSA;
	
	printf("Volume of the liquid: %.2f\n", liquid_vol);
	printf("Total surface area in contact with liquid: %.2f\n", liquid_touch);
	
	return 0;
}
