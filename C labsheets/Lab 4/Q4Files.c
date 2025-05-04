#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd, n;
  char buf[25];
  fd = open("/home/ali/Documents/lab44.dat", O_RDONLY);
  if(fd<0){
    printf("Error opening the file");
    return -1;
  }
  
  n = read(fd,buf,25);
  if(n<0){
    printf("Error reading from the file");
    return -1;
  }
  
  printf("%s", buf);
  close(fd);
}
