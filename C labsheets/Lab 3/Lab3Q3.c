#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
	char surname[50];
	char other_names[50];
	char address[100];
	int age;
};

void inputStudent(struct student *s){
	printf("Enter surname: ");
	scanf("%s", s->surname);
	printf("Enter other names: ");
	scanf("%s", s->other_names);
	printf("Enter address: ");
	scanf("%s", s->address);
	printf("Enter age: ");
	scanf("%d", &s->age);	
}

void displayStudent(struct student *s){
	printf("Surname of student: %s\n", s->surname);
	printf("Other names of student: %s\n", s->other_names);
	printf("Address of student: %s\n", s->address);
	printf("Age of student: %d\n", s->age);
}

int main(){
	struct student *stud[20];
	int young_age = 1000;
	int young_stud = 0;
	int n;

	printf("Input the number of entries\n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		stud[i] = (struct student *)malloc(sizeof(struct student));
		printf("Enter details for student %d\n", i+1);
		inputStudent(&stud[i]);
		if(stud[i]->age < young_age){
		young_age = stud[i].age;
		young_stud = i;
		}
	}
	printf("Youngest student : \n");
	displayStudent(&stud[young_stud]);

	for(int i = 0; i < n; i++){
		free(stud[i]);
	}
	return 0;
}

