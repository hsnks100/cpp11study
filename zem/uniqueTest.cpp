#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int main() {
    mutex m;
    thread t1([&]{
            int x = 0;
            m.lock();
            while( true ) {
                cout << x++ << endl;
            }
            m.unlock();
            });
    thread t2([&]{
            int a = 10000000;
            //unique_lock<timed_mutex> lck(m, adopt_lock);
            while( a-- ) {
                cout << "!!!!!!!!!!!!!!!!!" << endl;
            }
            });

    t1.join();
    t2.join();
}
