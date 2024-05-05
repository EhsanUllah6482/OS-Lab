
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int calculateSum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}


long long calculateProduct(int n)
{
    long long product = 1;
    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }
    return product;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        long long product = calculateProduct(n);
        printf("Child process calculated product: %lld\n", product);
    }
    else
    {
        int sum = calculateSum(n);
        printf("Parent process calculated sum: %d\n", sum);
    }

    return 0;
}
