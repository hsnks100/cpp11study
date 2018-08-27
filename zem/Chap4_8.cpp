#include <iostream>
#include <array>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

void Chapter04_array();
// void Chapter5_forward_list(); // just single-linked-list (single <list>)
void Chapter06_unordered_map(); // almost same with hash-map, but i don't know hash-map. So, i'll study this chapter personally...
void Chapter07_chrono();
void Chapter08_thread();


int main() {
	Chapter04_array();
	Chapter06_unordered_map();
	Chapter07_chrono();
	//Chapter08_thread();
	return 0;
}

void Chapter04_array() {
	// create & init, access
	std::array<int, 10> arr1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	/* access member */
	// for( int i = 0; i < arr1.size(); i++ )
	// for( array<int, 10>::iterator it = arr1.begin(); it != arr1.end(); it++ )
	// for( auto it = arr.begin(); it != arr.end(); it++ )
	// for( auto n : arr1)
	for (auto it = arr1.begin(); it != arr1.end(); it++) {
		cout << *it << endl;
	}

	// fill all space by value
	arr1.fill(123);
}

void Chapter06_unordered_map() {
	class Person {
	public:
		int id, age;
	public:
		Person(int id = 0, int age = 0) : id(id), age(age) {}
		void set(int _id, int _age) {
			id = _id; age = _age;
		}
	};

	unordered_map<int, Person> nameCards;
	Person insertPerson;
	insertPerson.set(930309, 26);
	nameCards.insert(unordered_map<int, Person>::value_type(1, insertPerson));

	insertPerson.set(960415, 23);
	nameCards.insert(std::pair<int, Person>(2, insertPerson));

	insertPerson.set(180818, 1);
	nameCards.insert(make_pair(2, insertPerson));

	insertPerson.set(102030, 9);
	nameCards[4] = insertPerson;

	for (auto it = nameCards.begin(); it != nameCards.end(); it++) {
		cout << it->first << " 's info\n";
		cout << "id = " << (it->second).id << ", age = " << it->second.age << endl;
	} // almost same with map too... (i think). auto sort..?

	  // find()
	auto it = nameCards.find(100);
	if (it == nameCards.end()) {
		cout << " fail to find 100 code person \n";
	}
	else {
		cout << "100 code person : " << it->second.id << " " << it->second.age << endl;
	}

	// if not exist, insert and return iterator (exist return iterator)
	insertPerson.set(121212, 7);
	auto iter = nameCards.emplace_hint(nameCards.begin(), 5, insertPerson);
	cout << iter->first << " " << iter->second.id << " " << iter->second.age << endl;

	// erase()
	nameCards.erase(100);

	// erase all
	nameCards.erase(nameCards.begin(), nameCards.end());
	nameCards.clear();
}

void Chapter07_chrono() {
	// basic
	chrono::system_clock::time_point sTime = chrono::system_clock::now();
	/* do something */

	// check time types
	chrono::system_clock::time_point eTime = chrono::system_clock::now();
	chrono::duration<double> defaultSec = eTime - sTime;
	chrono::nanoseconds nanoSec = eTime - sTime;
	chrono::microseconds microSec = chrono::duration_cast<chrono::microseconds>(eTime - sTime);
	chrono::milliseconds milliSec = chrono::duration_cast<chrono::milliseconds>(eTime - sTime);
	chrono::seconds sec = chrono::duration_cast<chrono::seconds>(eTime - sTime);
	chrono::minutes min = chrono::duration_cast<chrono::minutes>(eTime - sTime);
	chrono::hours hour = chrono::duration_cast<chrono::hours>(eTime - sTime);

	cout << defaultSec.count() << " default sec\n";
	cout << nanoSec.count() << " nano sec\n";
	cout << microSec.count() << " micro sec\n";
	cout << milliSec.count() << " milli sec\n";
	cout << sec.count() << " sec\n";
	cout << min.count() << " min\n";
	cout << hour.count() << " hour\n";

	// so many things, but i don't understand another things.......
	// ex1. Why use H1 + H2?

	// GetTick used in SDL too!.. study later.....
}

void Chapter08_thread() {
	// in my pc, sample code(without join) doesn't work....
	thread thread1([]() {
		for (int i = 0; i < 5; i++) {
			cout << "thread 1 - " << i << endl;
		}
	});
	thread1.join();

	thread thread2;
	thread2 = thread([]() {
		for (int i = 10; i < 15; i++) {
			cout << "thread 2 - " << i << endl;
		}
	});
	thread2.join();

	thread thread3 = thread([](int par) {
		for (int i = 20; i < 25; i++) {
			cout << "thread 3 - " << par << endl;
		}
	}, 4);
	thread3.join();
	mutex mtx_lock;
	int threadRunCount1 = 0;

	thread m_thread1;
	m_thread1 = thread([&]() {
        for(int i=0; i<10000000; i++);
		for (int i = 0; i < 5; i++) {
			threadRunCount1++;
			mtx_lock.lock();
			cout << "m_thread1's id = " << m_thread1.get_id() << endl;
			mtx_lock.unlock();
		}
	});

	int threadRunCount2 = 0;
	thread m_thread2;
	m_thread1 = thread([&]() {
        for(int i=0; i<10000000; i++);
		for (int i = 0; i < 5; i++) {
			threadRunCount2++;
			mtx_lock.lock();
			cout << "m_thread2's id = " << m_thread1.get_id() << endl;
			mtx_lock.unlock();
		}
	});

	while (threadRunCount1 < 3 && threadRunCount2 < 3);

	mtx_lock.lock();
	cout << "swap 1, 2" << endl;
	mtx_lock.unlock();

	m_thread1.swap(m_thread2);
	thread1.join();
	thread2.join();
}
