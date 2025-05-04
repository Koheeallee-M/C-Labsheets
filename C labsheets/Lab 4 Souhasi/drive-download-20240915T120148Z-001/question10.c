#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int fd;
    char name[100];
    char address[200];
    int namelength,addresslength;
    char choice;
    char buffer[256];
    fd = open("input13.dat", O_WRONLY|O_CREAT, S_IRWXU);
    if(fd<0){
        printf("Failed to open the file");
        return 1;
    }
    do
    {
     printf("Enter name:\n");//get name
     scanf("%s",name);
     printf("\n");
     namelength=strlen(name);//calculate length of name
     printf("Enter address:\n");//get address
     scanf("%s",address);
     printf("\n");
     addresslength=strlen(address);//calculate length of address
     //format data into buffer using snprintf
     int len=snprintf(buffer,sizeof(buffer),"Name length: %i\nName: %s\nAddress Length: %i\nAddress: %s\n", namelength,name,addresslength,address);
     //write formatted data to file
     if (write(fd, buffer, len) != len) {
            printf("Error writing to file");
        }
        
     printf("Do you want to add another person?(y/n): ");
     getchar();
     scanf("%c",&choice);
    } while (choice=='y'|| choice=='Y');
    close(fd);
    printf("Data successfully written to input13.dat.\n");
    return 0;
}