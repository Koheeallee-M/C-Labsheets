#include <stdio.h>
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
	struct student student1, student2;
	
	printf("Enter details for students 1:\n");
	inputStudent(&student1);
	
	printf("Enter details for students 2:\n");
	inputStudent(&student2);

	if(student1.age > student2.age){
		printf("Older student: \n");
		displayStudent(&student1);
	}
	else if(student1.age < student2.age){
		printf("Older student: \n");
		displayStudent(&student2);
	}
	else{
		printf("Same age. \n");
		printf("Student 1:\n");
		displayStudent(&student1);
		printf("Student 2: \n");
		displayStudent(&student2);
	}

	return 0;
}

