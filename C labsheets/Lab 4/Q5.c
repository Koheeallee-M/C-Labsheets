#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
  int fd, n;
  char name[20];
  char s_id[10];
  char dob[10];
  char gender[7];
  char m_status[10];
  char buffer[256];
  //opening file for writing or creating(not exist) and assigning access rights
  fd = open("lab45.dat", O_WRONLY|O_CREAT, S_IRWXU);
  if (fd<0){
    printf("Failed to open the file");
  }

  //reading data for 5 studentd from terminal
  for(int i = 0; i<5; i++){
    printf("Entering information for student %d:-\n", i+1);
    printf("Enter name:\n");
    scanf("%s",name);
    printf("Enter id:\n");
    scanf("%s", s_id);
    printf("Enter DOB:\n");
    scanf("%s",dob);
    printf("Enter gender:\n");
    scanf("%s",gender);
    printf("Enter marital status:\n");
    scanf("%s",m_status);
  }

//format data into buffer using snprintf
int len = snprintf(buffer, sizeof(buffer), "Name: %s\nID: %s\nDOB: %s\nGender: %s\nMarital Status: %s\n\n", name, s_id, dob, gender, m_status);
//write out formatted data to the file
	if(write(fd, buffer, len) != len){
	  printf("Error writing to the file");
	}
//close file
close(fd);
printf("Data written to lab45.dat successfully. \n");
return 0;
}
