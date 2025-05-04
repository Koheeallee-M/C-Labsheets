#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_STUDENTS 10

void *displayNames(void *arg) {
    char *names[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Harry", "Ivy", "Jack"};

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Name: %s\n", names[i]);
    }

    return NULL;
}

void *displayIDs(void *arg) {
    int ids[] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010};

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("ID: %d\n", ids[i]);
    }

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create threads
    pthread_create(&thread1, NULL, displayNames, NULL);
    pthread_create(&thread2, NULL, displayIDs, NULL);

    // Parent thread sleeps for 5 seconds
    sleep(5);

    printf("Parent Thread Exiting\n");

    // Join threads (optional)
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
