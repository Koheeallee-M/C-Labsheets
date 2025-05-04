#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int fd;
    char buffer[256];
    char name[100];
    char address[200];
    int namelength,addresslength;
    int maxNameLength =0,maxAddressLength=0;
    char longestName[100]="",longestAddress[200]="";
    char addressforlongestName[200]="",nameforlongestAddress[100]="";
    int addresslengthforlongestName=0,namelengthforlongestAddress=0;
    int totalNamelength=0,totalAddresslength=0;
    int nameCount =0,addressCount=0;
    //Open file for reading
    fd=open("/home/souhasi/Desktop/OS-C/input13.dat",O_RDONLY);
    if (fd<0){
        printf("Failed to open file");
        return 1;
    }
    //Read from the file till end of file(function read will return 0 if end of file is reached)
    while (read(fd,buffer,sizeof(buffer))>0){
        sscanf(buffer,"Name length: %i\nName: %s\nAddress Length: %i\nAddress: %s\n", &namelength,name,&addresslength,address);
        
        //Find longest name
        if (namelength>maxNameLength){
            maxNameLength=namelength;
            strcpy(longestName,name);
            strcpy(addressforlongestName,address);
            addresslengthforlongestName=addresslength;
        }
        //Find longest address
        if(addresslength>maxAddressLength){
            maxAddressLength=addresslength;
            strcpy(longestAddress,address);
            strcpy(nameforlongestAddress,name);
            namelengthforlongestAddress=namelength;
        }
        //calculate totals
        totalNamelength=totalNamelength+namelength;
        totalAddresslength=totalAddresslength+addresslength;
        nameCount++;
        addressCount++;

        //clear the buffer to avoid data overlap
        //memset(buffer,0,sizeof(buffer));
    }
    //calculate avg
    double avgNamelength= (double)totalNamelength/nameCount;
    double avgAdddresslength= (double)totalAddresslength/addressCount;
    close(fd);

    //display results
    printf("Longest name:-\n");
    printf("Name: %s\n",longestName);
    printf("Name length: %i\n",maxNameLength);
    printf("Address: %s\n",addressforlongestName);
    printf("Address Length: %i\n",addresslengthforlongestName);

    printf("Longest Address:-\n");
    printf("Name: %s\n",nameforlongestAddress);
    printf("Name length: %i\n",namelengthforlongestAddress);
    printf("Address: %s\n",longestAddress);
    printf("Address Length: %i\n",maxAddressLength);

    printf("Average size of names: %lf\n",avgNamelength);
    printf("Average size of addresses: %lf\n",avgAdddresslength);
    return 0;
}