#include <thread>
#include <future>
#include <iostream>
 
#include <chrono>
void taskLongTime(std::function<void(void)> callback) {
    std::thread([callback]() {
        std::future<int> f = std::async([]()->int {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return 1;
        });

        f.get();
        callback(); 
    }).detach();
}
void taskLongTime2(std::function<void(void)> callback) {
    std::thread([callback]() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        callback(); 
    }).detach();
}
 

void print_int (std::future<int>& fut) {
  int x = fut.get();
  std::cout << "value: " << x << '\n';
}

int main()
{
    taskLongTime([]() {
        printf("complete\n");
    });
    taskLongTime2([]() {
        printf("complete2\n");
    });
    printf("waiting....");



    std::promise<int> prom;                      // create promise 
    std::future<int> fut = prom.get_future();    // engagement with future 
    std::thread th1 (print_int, std::ref(fut));  // send future to new thread 
    prom.set_value (10);                         // fulfill promise
    // (synchronizes with getting the future)
    th1.join();
    getchar();
    //std::future<int> f = std::async(ThreadFunc);
    //std::cout << f.get() << std::endl;
 
    return 0;
}
