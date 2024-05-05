#include <iostream>
#include <pthread.h>
using namespace std;
void *task1(void *)
{
    cout << "Thread 1: Performing task 1" << endl;
    pthread_exit(NULL);
}

void *task2(void *)
{
    cout << "Thread 2: Performing task 2" << endl;
    pthread_exit(NULL);
}

void *task3(void *)
{
    cout << "Thread 3: Performing task 3" << endl;
    pthread_exit(NULL);
}

void *task4(void *)
{
    cout << "Thread 4: Performing task 4" << endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2, thread3, thread4;
    pthread_create(&thread1, NULL, task1, NULL);
    pthread_create(&thread2, NULL, task2, NULL);
    pthread_create(&thread3, NULL, task3, NULL);
    pthread_create(&thread4, NULL, task4, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    cout << "All threads have finished their tasks." << endl;

    return 0;
}
