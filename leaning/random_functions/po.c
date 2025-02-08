#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1)
        return 1;

    int fd_in = open("po", O_CREAT | O_RDONLY);
    if (fd_in == -1)
        return 1;

    int fd_out = open("po2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out == -1) {
        close(fd_in);
        return 1;
    }

    // Fork a process to handle reading from po and writing to po2
    if (fork() == 0) {
        // Child process: Read a number from "po" and write to the pipe
        close(pipe_fd[0]); // Close read end of pipe in child

        int number = 2;
        read(fd_in, &number, sizeof(number)); // Read a number from po
        write(pipe_fd[1], &number, sizeof(number)); // Send it through the pipe

        close(pipe_fd[1]); // Close write end of pipe
        close(fd_in);      // Close input file
    } else {
        // Parent process: Read from pipe and write the number to "po2"
        close(pipe_fd[1]); // Close write end of pipe in parent

        int number;
        read(pipe_fd[0], &number, sizeof(number)); // Read the number from the pipe
        write(fd_out, &number, sizeof(number));    // Write it to po2

        close(pipe_fd[0]); // Close read end of pipe
        close(fd_out);     // Close output file
    }

    return 0;
}
