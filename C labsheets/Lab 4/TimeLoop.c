#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
pid_t p_id;
p_id = getpid();

struct timeval timestart;
gettimeofday(&timestart, NULL);
for(int i = 0; i<=5; i++){
sleep(2);
} 

struct timeval timeend;
gettimeofday(&timeend, NULL);

double duration = (timeend.tv_sec - timestart.tv_sec) + ((timeend.tv_usec - timestart.tv_usec)/1000000000.0);

printf("Program with pid %d has run for %lf\n" ,p_id ,duration);
return 0;
}
