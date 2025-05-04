#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    char name[20];
    char sid[10];
    char dob[10];
    char gender[7];
    char mstatus[10];
    char buffer[256];
    int fd;
    //Open file for appending data
    fd = open("/home/souhasi/Desktop/OS-C/lab45.dat",O_WRONLY|O_APPEND);
    if (fd<0){
        printf("Failed to open file");
        return 1;
    }
    printf("Entering information for 5 more students:-\n");
    for (int i=0;i<5;i++){
        printf("Entering information for student %i:-\n",i+1);
        printf("Enter name:\n");
        scanf("%s",name);
        printf("Enter ID:\n");
        scanf("%s",sid);
        printf("Enter DOB:\n");
        scanf("%s",dob);
        printf("Enter gender:\n");
        scanf("%s",gender);
        printf("Enter marital status:\n");
        scanf("%s",mstatus);

        //format data into buffer using snprintf
        int len = snprintf(buffer, sizeof(buffer),"Name: %s\nID: %s\nDOB: %s\nGender: %s\nMarital status: %s\n\n",name, sid, dob, gender, mstatus);

     // Write the formatted data to the file
        if (write(fd, buffer, len) != len) {
            printf("Error writing to file");
        }
    }
    close(fd);
    printf("Data written to lab45.dat successfully.\n");
    //Opening file for reading
    ssize_t n;
    char buf[256];
    fd = open("/home/souhasi/Desktop/OS-C/lab45.dat",O_RDONLY);
    if (fd<0){
        printf("Failed to open file");
        return 1;
    }
    printf("Data from lab45.dat:\n");
    while((n=read(fd,buf,sizeof(buf)-1))>0){
        buf[n]='\0';
        printf("%s",buf);
    }
    if (n<0){
        printf("Failed to read the file");
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}