#include <stdio.h>
#include <unistd.h>

int main()
{
    int counter = 0;

    // Fork into two processes
    int pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("Child process. PID: %d\n", getpid());
        for (int i = 0; i < 1000000; ++i)
        {
            counter++;
        }
        printf("Child counter value: %d\n", counter);
    }
    else if (pid > 0)
    {
        // Parent process
        printf("Parent process. PID: %d, Child PID: %d\n", getpid(), pid);
        for (int i = 0; i < 1000000; ++i)
        {
            counter++;
        }
        printf("Parent counter value: %d\n", counter);
    }
    else
    {
        // Error occurred
        perror("fork");
        return 1;
    }

    return 0;
}
