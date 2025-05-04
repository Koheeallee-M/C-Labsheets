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
    int fd,n;
    struct Student Array[5];
    //opening file for writing or creating(not exist) and assigning access rights
    fd=open("lab46.dat",O_WRONLY|O_CREAT,S_IRWXU);
    if (fd<0){
        printf("Failed to open the file");
        return 1;
    }
    //reading data for 5 students from terminal
    printf("Entering information for 5 students:-\n");
    for (int i=0;i<5;i++){
        printf("Enter name %i:\n",i+1);
        scanf("%s", Array[i].name);
        printf("Enter ID %i:\n",i+1);
        scanf("%s", Array[i].sid);
        printf("Enter DOB %i:\n",i+1);
        scanf("%s", Array[i].dob);
        printf("Enter gender %i:\n",i+1);
        scanf("%s", Array[i].gender);
        printf("Enter marital status %i:\n",i+1);
        scanf("%s", Array[i].mstatus);
    }
    //writing data to file in correct formatting
    for(int i=0;i<5;i++){
        write(fd,&Array[i],sizeof(struct Student));
    }
    //close file
    close(fd);
    printf("Data written to lab46.dat successfully.\n");
    //opening file for reading
    fd = open("lab46.dat",O_RDONLY);
    if (fd<0){
        printf("Failed to open file");
        return 1;
    }
    struct Student student;
    printf("Reading data from lab46.dat:\n");
    while(read(fd,&student,sizeof(struct Student))>0){
    printf("Name: %s\nID: %s\nDOB: %s\nGender: %s\nMarital status: %s\n\n", student.name, student.sid, student.dob, student.gender, student.mstatus);
   }
   //close file
   close(fd);
    return 0;
}