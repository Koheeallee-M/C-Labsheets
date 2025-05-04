#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("I am the child process. My PID is: %d\n", getpid());
        printf("My parent's PID is: %d\n", getppid());
        while (1) {
            sleep(1);
            printf("Child process waking up...\n");
        }
    } else {
        printf("I am the parent process. My PID is: %d\n", getpid());
        printf("My child's PID is: %d\n", pid);
        while (1) {
            sleep(1);
            printf("Parent process waking up...\n");
        }
    }

    return 0;
}

