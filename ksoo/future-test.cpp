#include <thread>
#include <future>
#include <iostream>
 
#include <chrono>
#include <vector>
void taskLongTime(std::function<void(void)> callback) {
    
    std::vector<std::future<void>>  futures;
    futures.push_back(
        std::async([callback]()->void {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            callback();
        }));

    futures.push_back(
        std::async([]()->void {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        printf("...1!!\n");
    }));
    futures.push_back(
        std::async([]()->void {
        std::this_thread::sleep_for(std::chrono::seconds(7));
        printf("...2!!\n");
    }));

    for(auto const& i: futures) {
        i.get();
    } 
}
 

void print_int (std::future<int>& fut) {
  int x = fut.get();
  std::cout << "value: " << x << '\n';
}

void print_int2 (std::promise<int>& pros) {
  pros.set_value(30);
}

#include <string>
#include <chrono>
#include <thread>
#include <future>
 
using namespace std::chrono;
 
std::string fetchDataFromDB(std::string recvdData)
{
	// Make sure that function takes 5 seconds to complete
	std::this_thread::sleep_for(seconds(5));
 
	//Do stuff like creating DB Connection and fetching Data
	return "DB_" + recvdData;
}
 
std::string fetchDataFromFile(std::string recvdData)
{
	// Make sure that function takes 5 seconds to complete
	std::this_thread::sleep_for(seconds(5));
 
	//Do stuff like fetching Data File
	return "File_" + recvdData;
}
 
int main()
{
    taskLongTime([]() {
        printf("complete\n");
    });

	std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");
	std::string fileData = fetchDataFromFile("Data");
	std::string dbData = resultFromDB.get();
	std::string data = dbData + " :: " + fileData;
	std::cout << "Data = " << data << std::endl;
    printf("waiting....");
    getchar();
    //std::future<int> f = std::async(ThreadFunc);
    //std::cout << f.get() << std::endl;
 
    return 0;
}
