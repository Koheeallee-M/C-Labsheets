#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	struct timeval start, end;
	double seconds, useconds, mseconds;
	int n;
	printf("Enter number of times loop will execute: ");
	scanf("%i", &n);
	
	for(int i=1; i<=n; i++){
	gettimeofday(&start, NULL);
	printf("Sleeping for 2 seconds...\n");
	sleep(2);
	pid_t pid = getpid();
	gettimeofday(&end, NULL);
	seconds = end.tv_sec - start.tv_sec;
	useconds = end.tv_usec - start.tv_usec;
	mseconds = (seconds*1000) + (useconds/1000.0);
	printf("Program with pid %id has run for %lf milliseconds.\n", pid, mseconds);
	}
	return 0;
}

