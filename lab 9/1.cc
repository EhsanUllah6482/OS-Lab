#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int globalVariable = 0;
int result = 0;
mutex mtx; 
void threadFunction(int id)
 {
    for (int i = 0; i < 100000; ++i) {
        mtx.lock(); 
        globalVariable++;
        result += globalVariable; 
        mtx.unlock(); 
    }
}

int main() {
    thread t1(threadFunction, 1);
    thread t2(threadFunction, 2);
    thread t3(threadFunction, 3);

    t1.join();
    t2.join();
    t3.join();
    cout << "Final value of globalVariable: " << globalVariable << endl;
    cout << "Final value of result: " << result << endl;

    return 0;
}
