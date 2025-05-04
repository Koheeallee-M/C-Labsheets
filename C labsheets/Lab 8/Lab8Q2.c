#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    int fd, pipefd[2];
    char buffer[20];
    int n;

    // Open the file for reading
    fd = open("/home/ali/Desktop/myfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        return 1;
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) { // Child process
        close(pipefd[1]); // Close the write end of the pipe

        while ((n = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, n);
        }

        close(pipefd[0]);
    } else { // Parent process
        close(pipefd[0]); // Close the read end of the pipe

        while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
            write(pipefd[1], buffer, n);
        }

        close(pipefd[1]);
        close(fd);
    }

    return 0;
}
