/*Write a program that allows user to populate a global array, the program should create 2 threads, one displays even, the other even.
User can choose which thread runs first
Use mutex locks to ensure the first thread finishes before the other displays its elements*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_ELEMENTS 10

int numbers[MAX_ELEMENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *displayEvenNumbers(void *arg){
 pthread_mutex_lock(&mutex);

 printf("Even numbers:\n");
 for(int i = 0; i < MAX_ELEMENTS; i++){
  if(numbers[i] % 2 == 0){
   printf("%d", numbers[i]);
   printf("\t");
   }
 }
  printf("\n");

  pthread_mutex_unlock(&mutex);
  return NULL;

}

void *displayOddNumbers(void *arg){
 pthread_mutex_lock(&mutex);
 printf("Odd numbers:\n");
 for(int i = 0; i < MAX_ELEMENTS; i++){
  if(numbers[i] % 2 != 0){
   printf("%d", numbers[i]);
   printf("\t");
  }
 }
 printf("\n");
 pthread_mutex_unlock(&mutex);
 return NULL;
}


int main(){
 int choice;
 pthread_t thread1, thread2;

 printf("Enter 10 integers:\n");
 for(int i = 0; i < MAX_ELEMENTS; i++){
  scanf("%d", &numbers[i]);
 }

 printf("Input 1 for even numbers, 2 for odd");
 scanf("%d", &choice);

 if(choice == 1){
  pthread_create(&thread1, NULL, displayEvenNumbers, NULL);
  pthread_create(&thread2, NULL, displayOddNumbers, NULL);
 }
 else{
  pthread_create(&thread2, NULL, displayOddNumbers, NULL);
  pthread_create(&thread1, NULL, displayEvenNumbers, NULL);
 }

 pthread_join(thread1, NULL);
 pthread_join(thread2, NULL);

 return 0;
}
