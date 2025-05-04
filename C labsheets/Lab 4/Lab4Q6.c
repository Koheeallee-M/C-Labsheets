#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd;
	ssize_t n;
	char buffer[256];
	fd = open("/home/ali/Desktop/lab45.dat", O_RDONLY);
	if (fd<0){
		printf("Failed to open file");
		return 1;
	}
	printf("Data from lab45.dat:\n");
	
	while((n=read(fd,buffer,sizeof(buffer)-1))>0){
		buffer[n] = '\0';
		printf("%s", buffer);
	}
	if (n < 0){
		printf("Failed to read the file");
		close(fd);
		return 1;
	}
	close(fd);
	return 0;
}
