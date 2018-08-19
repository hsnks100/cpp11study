#include <chrono>
#include <cmath>
#include <iostream>

int main()
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    float t = sqrt(44);
    for(int i=0; i<1000000000; i++) {
        t += sqrt(444);
    }
    std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
    std::cout << "Test() 함수를 수행하는 데 걸린 시간(초): " << sec.count() << "seconds" << std::endl;
    std::cout << t << std::endl;
    return 0;
}
