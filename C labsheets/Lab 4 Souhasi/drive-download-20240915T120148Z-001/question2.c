#include<stdio.h>
#include<sys/time.h>

float Power(float X, int n){
    if (n==0){
        return 1.0;
    }else if (n>0){
        return X * Power(X, n-1);
    }
}
int main(){
    struct timeval start,end;
    double seconds,useconds,mseconds;
    float valueX, result100,result99,result98,Result;
    
    printf("Enter value of X:\n");
    scanf("%f",&valueX);
    gettimeofday(&start,NULL);
    result100 = Power(valueX,100);
    result99 = Power(valueX,99);
    result98 = Power(valueX,98);
    Result = result100 + result99 + result98;
    printf("Result: %f\n" , Result);
    gettimeofday(&end,NULL);
    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mseconds=useconds/1000.0;
    printf("Duration of program: %lf seconds %lf milliseconds\n" , seconds, mseconds);
    return 0;
}