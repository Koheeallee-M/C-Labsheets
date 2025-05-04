#include <stdio.h>
#include <sys/time.h>

int Power(int x, int n){
if(n == 0){
return 1;
}
else{
return x * Power(x, n-1);
}

}
int main(){
double timestart;
double timeend;
double timetaken;
int x, x8, x9, x0, sum;
printf("Please enter a value for x: ");
scanf("%d", &x);
  struct timeval current_time;
  gettimeofday(&current_time,NULL);
  timestart = current_time.tv_usec;
  
  x8 = Power(x,98);
  x9 = x8 * x;
  x0 = x9 * x;
  sum = x0 + x9 + x8;
  
  struct timeval now_time;
  gettimeofday(&now_time,NULL);
  timeend = now_time.tv_usec;
  
  timetaken = timeend - timestart;
  
  printf("The answer is %d\n", sum);
  printf("Time to process is %lf\n", timetaken);
return 0;
}
