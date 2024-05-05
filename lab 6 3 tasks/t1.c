#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int n = 5; 
    int i;

    printf("Parent process id: %d\n", getpid());

    for (i = 0; i < n; i++)
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            fprintf(stderr, "Fork failed\n");
            return 1;
        }
        else if (pid == 0)
        {
            // Child process
            printf("Child process id: %d, parent id: %d\n", getpid(), getppid());
            exit(0);
        }
    }

    // Parent process waits for all child processes to complete
    for (i = 0; i < n; i++)
    {
        wait(NULL);
    }

    return 0;
}
