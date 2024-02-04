### How to run c++ file in linux

First make .cc file and write this code in it

`// hello.cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}`

![](D:\Fourth Samester\Operating system\lab\Lab2\1.png)

Then go to your terminal and run this command



g++ -obj hello hello.cpp



It will make object file 



Now type this command and you will get your output



./hello

