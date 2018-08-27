#include <iostream>
#include <cstdio>
#include <atomic>
#include <bitset> // bit operator

using namespace std;

void callLockFreeTypes();
void checkLockFree(int LockStatus, const char* charSet);
void load_store();
void operateLock();
void exchangeValues();
 
int main() {
	// almost atomic_~~~ function return before value.
	/* 10-1) check lock free */
	callLockFreeTypes();
	/* 10-2) load, store */
	load_store();
	/* 10-3) operate */
	operateLock();
	/* 10-4 exchange values */
	exchangeValues();
}
 
void checkLockFree(int LockStatus, const char* charSet) {
	cout.width(9); cout << charSet;
	cout << " : " << LockStatus << " = ";
	switch (LockStatus) {
	case 0:
		cout << "NO lock free\n"; break;
	case 1:
		cout << "can be lock free\n"; break;
	case 2:
		cout << "run lock-free\n"; break;
	default:
		cout << "i don't know this status " << LockStatus << endl;
		break;
	}
}

void callLockFreeTypes() {
	checkLockFree(ATOMIC_BOOL_LOCK_FREE, "bool");
	checkLockFree(ATOMIC_CHAR_LOCK_FREE, "char");
	checkLockFree(ATOMIC_CHAR16_T_LOCK_FREE, "char16_t");
	checkLockFree(ATOMIC_CHAR32_T_LOCK_FREE, "char32_t");
	checkLockFree(ATOMIC_WCHAR_T_LOCK_FREE, "wchar_t");
	checkLockFree(ATOMIC_SHORT_LOCK_FREE, "short");
	checkLockFree(ATOMIC_INT_LOCK_FREE, "int");
	checkLockFree(ATOMIC_LONG_LOCK_FREE, "long");
	checkLockFree(ATOMIC_LLONG_LOCK_FREE, "long long");
	checkLockFree(ATOMIC_POINTER_LOCK_FREE, "<T> *");
}

void load_store() {
	atomic<int> a(0), b(1);
	cout << a << " " << b << endl;
	atomic_store(&a, 3);
	int result = atomic_load(&a); // 명시적 사용
	int result2 = b; // 암묵적 사용
}
 
void operateLock() {
	atomic<int> num1(10);
	atomic_fetch_add(&num1, 5); cout << num1 << endl; // 10 + 5
	atomic_fetch_sub(&num1, 3); cout << num1 << endl; // 15 - 3
 
	int a = 0x0b; // 1011
	int b = 0x0e; // 1110
	atomic<int> num2(a);
	atomic_fetch_and(&num2, b); // num2 = 1010
	cout << "          a : " << bitset<4>(a).to_string() << endl;
	cout << "          b : " << bitset<4>(b).to_string() << endl;
	cout << "AND OPERATE : " << bitset<4>(num2).to_string() << endl;
 
	atomic<int> num3(a);
	atomic_fetch_or(&num3, b); // num3 = 1111
	cout << "          a : " << bitset<4>(a).to_string() << endl;
	cout << "          b : " << bitset<4>(b).to_string() << endl;
	cout << "AND OPERATE : " << bitset<4>(num3).to_string() << endl;
 
	atomic<int> num4(a);
	atomic_fetch_xor(&num4, b); // num4 = 0101
	cout << "          a : " << bitset<4>(a).to_string() << endl;
	cout << "          b : " << bitset<4>(b).to_string() << endl;
	cout << "AND OPERATE : " << bitset<4>(num4).to_string() << endl;
}
 
void exchangeValues() {
	atomic<int> num1(10);
	if (atomic_exchange(&num1, 20) == 10)
		cout << "exchange success" << endl;
	
	atomic<int> num2(20);
	int expectValue2 = 21;
 
	if (atomic_compare_exchange_strong(&num2, &expectValue2, 1)) {
		cout << "num2 = expectValue2" << endl;
	}
	else {
		cout << "num2 != expectValue2" << endl;
	}
 
	atomic<int> num3(30);
	int expectValue3 = 30;
	if (atomic_compare_exchange_strong(&num3, &expectValue3, 1)) {
		cout << "num3 = expectValue3" << endl;
	}
	else {
		cout << "num3 != expectValue3" << endl;
	}
}
