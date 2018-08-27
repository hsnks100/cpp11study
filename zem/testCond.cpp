#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

thread_local int nCount = 0;
mutex mtx_lock;

void Test() {
    for(int i=0; i<10; i++) {
        nCount++;
    }
    cout << nCount << endl;
}

int main() {
    /*
    thread T1, T2, T3;
    T1 = thread([]{Test();});
    T2 = thread([]{Test();});
    T3 = thread([]{Test();});
    T1.join();
    T2.join();
    T3.join();
*/
    mutex mtx_lock;
    condition_variable Cond;

    thread t1([&] {
            for(int i=0; i<5; i++) {
            cout << "T1 : " << i << endl;
            }
            Cond.notify_one();
            });
    thread t2([&]{
            unique_lock<mutex> uniq_lock(mtx_lock);
            Cond.wait(uniq_lock);
            for(int i=10; i<15; i++) {
            cout << "T2 : " << i << endl;
            }
            Cond.notify_one();
            });
    thread t3([&]{
            unique_lock<mutex> uniq_lock(mtx_lock);
            Cond.wait(uniq_lock);
            for(int i=20; i<25; i++) {
            cout << "T3 : " << i << endl;
            }
            Cond.notify_one();
        });

    t1.join(); t2.join(); t3.join();

    return 0;
}
 
