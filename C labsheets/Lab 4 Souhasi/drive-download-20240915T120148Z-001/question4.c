#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd,n;
    char buf[60];
    //opening file for reading
    fd = open("/home/souhasi/Desktop/OS-C/lab44.dat", O_RDONLY);
    if (fd<0){
        printf("Failed to open the file");
        return 1;
    }
    //Reading 55 bytes from the file
    n= read(fd,buf,55);
    if (n<0){
        printf("Failed to read the file");
        close(fd);
        return 1;
    }
    //Displaying contents of the file
    printf("Contents of the file:\n%s\n",buf);
    //close the file
    close(fd);
return 0;
}