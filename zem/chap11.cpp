#include <future>
#include <iostream>
#include <thread>
#include <chrono>
 
using namespace std;
 
void async_deferred();
int getMoneyFromDatabase(int charCd);
 
int main() {
	/* 11-1) async/future call function example */
	async_deferred();
}
 
void async_deferred() {
	auto ThreadID = this_thread::get_id();
	cout << "Main Thread ID : " << ThreadID << endl;
	cout << "async(std::launch::async, getMoneyFromDatabase)" << endl;
	// async() run async Right Away
	future<int> future1 = async(std::launch::async, getMoneyFromDatabase, 10);
	//std::this_thread.sleep_for(std::chrono::milliseconds(10)); // window don't work this F
	cout << "wait 10 ms in Main Thread" << endl;
 
	auto result1 = future1.get();
	cout << "return Value = " << result1 << endl;
	cout << endl;
 
	cout << "async(std::launch::deferred, getMoneyFromDatabase)" << endl;
	// deferred run async, wait for result.
	future<int> future2 = async(std::launch::deferred, getMoneyFromDatabase, 20);
	//std::this_thread.sleep_for(std::chrono::milliseconds(10)); // window don't work this F
	cout << "wait 10 ms in Main Thread" << endl;
 
	auto result2 = future2.get();
	cout << "return Value = " << result2 << endl;
	cout << endl;
}

int getMoneyFromDatabase(int charCd) {
	auto ThreadID = this_thread::get_id();
	cout << "Get money from db, thread ID : " << ThreadID << endl;
	return charCd;
}

