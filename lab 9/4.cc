#include <iostream>
#include <pthread.h>
#include <unistd.h> 
using namespace std;
void *threadFunction(void *arg)
{
    long thread_id = (long)arg;
    pid_t process_id = getpid(); 
    cout << "Thread " << thread_id << ": Thread ID: " << pthread_self()<< ", Process ID: " << process_id << endl;
    pthread_exit(NULL);
}

int main()
{
    const int numThreads = 4;
    pthread_t threads[numThreads];
    for (long i = 0; i < numThreads; ++i)
    {
        pthread_create(&threads[i], NULL, threadFunction, (void *)i);
    }

    for (int i = 0; i < numThreads; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
