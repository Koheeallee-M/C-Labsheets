#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    int fd_in, fd_out, pipefd[2];
    char buffer[20];
    int n;

    // Open the input file for reading
    fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1) {
        perror("Error opening input file");
        return 1;
    }

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        return 1;
    }

    // Open the output file for writing
    fd_out = open(argv[2], O_WRONLY | O_CREAT, 0666);
    if (fd_out == -1) {
        perror("Error opening output file");
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
            write(fd_out, buffer, n);
        }

        close(pipefd[0]);
        close(fd_out);
    } else { // Parent process
        close(pipefd[0]); // Close the read end of the pipe

        while ((n = read(fd_in, buffer, sizeof(buffer))) > 0) {
            write(pipefd[1], buffer, n);
        }

        close(pipefd[1]);
        close(fd_in);
    }

    return 0;
}
