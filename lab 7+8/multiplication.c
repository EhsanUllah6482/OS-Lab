#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Executing multiplication.c\n");

    // Call exec to replace current process with addition
    if (execl("./addition", "addition", NULL) == -1)
    {
        perror("exec");
        exit(EXIT_FAILURE);
    }

    // This part will not be executed if exec succeeds
    printf("This line will not be executed.\n");
    return 0;
}
