#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
struct Student{
    char name[20];
    char sid[10];
    char dob[10];
    char gender[7];
    char mstatus[10];
};
int main(){
    int fd,studentNum;
    struct Student student;
    fd = open("lab46.dat", O_RDONLY);//open file for read
    if (fd<0){
        printf("Failed to open the file");
        return 1;
    }
    //prompt user to enter student number
    printf("Enter the student number to display(1-5): ");
    scanf("%i",&studentNum);
    //move the file pointer to the correct position using lseek
    off_t offset = (studentNum-1) * sizeof(struct Student);
    if (lseek(fd,offset,SEEK_SET)== -1){
        printf("Error using lseek");
        close(fd);
        return 1;
    }
    //read the srudent record
    if(read(fd,&student,sizeof(struct Student))<=0){
        printf("Error reading student data");
        close(fd);
        return 1;
    }
    //Display student information
    printf("Student %i Information:\n", studentNum);
    printf("Name: %s\nID: %s\nDOB: %s\nGender: %s\nMarital status: %s\n\n", student.name, student.sid, student.dob, student.gender, student.mstatus);
    //close file
    close(fd);
    return 0;
}