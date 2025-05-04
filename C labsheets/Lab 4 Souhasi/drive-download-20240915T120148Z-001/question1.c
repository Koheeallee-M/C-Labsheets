#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("Process ID(PID) : %i\n" , pid);
    printf("Parent Process ID(PID) : %i\n" , ppid);

    printf("Sleeping for 30 seconds...\n");
    sleep(30);
    return 0;
}