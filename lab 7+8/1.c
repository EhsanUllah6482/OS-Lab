#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3;

    // Create first child
    pid1 = fork();

    // Check for error
    if (pid1 < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid1 == 0) {
        // Child process 1
        printf("Child 1 - My PID is: %d\n", getpid());
        exit(0);
    } else {
        // Parent process
        // Create second child
        pid2 = fork();

        // Check for error
        if (pid2 < 0) {
            fprintf(stderr, "Fork failed\n");
            return 1;
        } else if (pid2 == 0) {
            // Child process 2
            printf("Child 2 - My PID is: %d\n", getpid());
            exit(0);
        } else {
            // Parent process
            // Create third child
            pid3 = fork();

            // Check for error
            if (pid3 < 0) {
                fprintf(stderr, "Fork failed\n");
                return 1;
            } else if (pid3 == 0) {
                // Child process 3
                printf("Child 3 - My PID is: %d\n", getpid());
                exit(0);
            } else {
                // Parent process
                printf("Parent - My PID is: %d\n", getpid());
                // Wait for all child processes to finish
                wait(NULL);
                wait(NULL);
                wait(NULL);
            }
        }
    }

    return 0;
}
