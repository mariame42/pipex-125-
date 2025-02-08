#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

int main(int ac, char **av) {
    int pid = fork();
    if (pid == -1) {
        perror("fork");  // Print error message if fork fails
        return 1;
    }

    if (pid == 0) {
        // Child process
        int err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
        if (err == -1) {
            perror("could not find program to execute");  // Corrected typo and error message
            return 2;
        }
    } else {
        // Parent process
        int wstatus;
        wait(&wstatus);
        if (WIFEXITED(wstatus)) {
            int statuscode = WEXITSTATUS(wstatus);
            if (statuscode == 0) {
                printf("success\n");
            } else {
                printf("failure with status code %d\n", statuscode);  // Use printf for custom message
            }
        } else {
            printf("Child process did not terminate normally\n");
        }
    }
    return 0;
}


// https://youtu.be/DiNmwwQWl0g?si=y_G2Z23HQYFluUul
