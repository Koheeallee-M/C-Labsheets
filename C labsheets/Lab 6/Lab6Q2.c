#include <stdio.h>
#include <unistd.h>

int main() {
    int n;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("I am the child process. My PID is: %d\n", getpid());
        printf("Even elements: ");
        for (int i = 0; i < n; i += 2) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    } else {
        printf("I am the parent process. My PID is: %d\n", getpid());
        printf("Odd elements: ");
        for (int i = 1; i < n; i += 2) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    }

    return 0;
}

