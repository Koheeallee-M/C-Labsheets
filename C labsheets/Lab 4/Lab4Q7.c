#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	char name[20];
	char s_id[10];
	char dob[10];
	char gender[6];
	char m_status[10];
	char buffer[256];
	int fd;
	//Opening file for appending data
	fd = open("/home/ali/Desktop/lab45.dat", O_WRONLY|O_APPEND);
	if(fd<0){
	printf("Failed to open file");
	return -1;
	}
	printf("Enter information for five extra students\n");
	for(int i = 0; i<5; i++){
		printf("Entering info for student %i:-\n", i+1);
		printf("Enter name: \n");
		scanf("%s", name);
		printf("Enter id: \n");
		scanf("%s", s_id);
		printf("Enter DOB: \n");
		scanf("%s", dob);
		printf("Enter gender: \n");
		scanf("%s", gender);
		printf("Enter marital status: \n");
		scanf("%s", m_status);
		//format data into buffer using snprintf
		int len = snprintf(buffer, sizeof(buffer), "Name: %s\nID: %s\nDOB: %s\nGender: %s\nMarital Status: %s\n\n", name, s_id, dob, gender, m_status);
		//Write formatted data into file
		if (write(fd, buffer, len)!=len){
			printf("Error writing to file");
		}
	}
	close(fd);
	printf("Data successfully entered into file");
	return 0;
}
