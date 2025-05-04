#include <stdio.h>
#include <string.h>

int main(){
	char surname[50], firstname[50], address[100];
	
	printf("Please enter your surname\n");
	scanf("%s", surname);
	printf("Please enter your first name\n");
	scanf("%s", firstname);
	printf("Please enter your address\n");
        scanf("%s", address);

	printf("%s\n", surname);
	printf("%s\n", firstname);
	printf("%s\n", address);
	
	return 0;
}
