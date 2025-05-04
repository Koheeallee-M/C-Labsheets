#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
pid_t pid, ppid;

pid = getpid();
ppid = getppid();

printf("Process ID (PID): %d\n" , pid);
printf("Parent Process ID (PPID): %d\n" , ppid);

sleep(5);

return 0;
}
