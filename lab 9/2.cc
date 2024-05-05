#include <iostream>
#include <pthread.h>
using namespace std;
void *print(void *arg)
{
    pthread_t id = pthread_self();
    cout << "Hello, I am thread " << *((int *)arg) << " my ID is " << id << endl;
    pthread_exit(NULL);
}

int main()
{
    int numThreads;
    cout << "Enter the number of threads to create: ";
    cin >> numThreads;

    pthread_t threads[numThreads];
    int threadArgs[numThreads];
    for (int i = 0; i < numThreads; ++i)
    {
        threadArgs[i] = i + 1;
        pthread_create(&threads[i], NULL, print, (void *)&threadArgs[i]);
    }
    for (int i = 0; i < numThreads; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    exit(0);
}
