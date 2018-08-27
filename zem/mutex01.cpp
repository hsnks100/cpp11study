#include <thread>
#include <iostream>
#include <mutex>

int main() {
    std::mutex mtx_lock;

    std::thread Thread1([&]() {
        for(int i=0; i<5; i++) {
            mtx_lock.lock();
            std::cout<<"Thread 1's " << i << std::endl;
            mtx_lock.unlock();
        }
    });

    std::thread Thread2;
    Thread2 = std::thread([&]() {
        for(int i=10; i<15; i++) {
            mtx_lock.lock();
            std::cout << "Thread 2's " << i << std::endl;
            mtx_lock.unlock();
        }
    });

    std::thread Thread3([&]() {
        for(int i=20; i<25; i++) {
            mtx_lock.lock();
            std::cout << "Thread 3's " << i << std::endl;
            mtx_lock.unlock();
        }
    });

    if( Thread1.joinable() ) Thread1.join();
    if( Thread2.joinable() ) Thread2.join();
    if( Thread3.joinable() ) Thread3.join();

    return 0;

}
