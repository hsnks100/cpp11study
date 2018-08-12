#include 
#include 
#include 
#include // for use shared_ptr, unique_ptr
#include // for use tuple
using namespace std;

void setInit(int &a, int &b, int &c) {
    a = 1; b = 2; c = 3;
}

class TestForSharedPtr {
public :
    int iv;
    char cv;
    static int classCount;
    TestForSharedPtr(int i = 0, char c = '\0') : iv(i), cv(c) {
        printf("%d's TestClass created\n", ++classCount);
    }
    ~TestForSharedPtr() {
        printf("%d's TestClass deleted\n", classCount--);
    }
};

int TestForSharedPtr::classCount = 0;

int main() {
    int a, b, c;

    /* lambda basic info
       [] : start lambda function
       () : parameter
       {} : define funtion
       (); : run lambda function
       */

    /* About Capture */
    /* for copy all values, use [=] or [ ] */
    setInit(a, b, c);
    [=]() {
        // a = 100; // = is only for copy
        printf("Step 1 : a(%d), b(%d), c(%d)\n", a, b, c);
    }();

    /* for reference all values, use [&] or [ & ] */
    setInit(a, b, c);
    [&]() {
        a = 100; b = 200; c = 300;
        printf("Step 2 : a(%d), b(%d), c(%d)\n", a, b, c);
    }();

    /* use copy & reference both */
    setInit(a, b, c);
    [=, &a, &c] {
        a = 100; /* b = 200; */ c = 300;
        printf("Step 3 : a(%d), b(%d), c(%d)\n", a, b, c);
    }();

    /* use copy, but have to change some values, use mutable */
    setInit(a, b, c);
    [=]() mutable {
        a = 100; b = 200; c = 300;
        printf("Step 4 : a(%d), b(%d), c(%d)\n", a, b, c);
    }();


    /* different format about for loop */
    int numList[] = { 1, 2, 3, 4, 5 };
    /* basic for loop */
    for (int i = 0; i < 5; i++) {
        printf("%d\n", numList[i]);
    }

    /* use for each */
    /* i don't know why my pc don't accept this problem
       for each(int i in numList) {

       }*/

    /* range based */
    for (auto i : numList) {
        printf("%d\n", i); // not numList[i];
    }

    /* range based, value could change if you use & */
    for (auto &i : numList) {
        printf("%d\n", ++i);
    }

    /* NULL -> nullptr */
    char *buf = nullptr;
    if (buf) printf("%s", buf);
    // if (nullptr) printf("%s", buf); // a book describe this error, but VS can compile this sentence

    TestForSharedPtr *tc1 = new TestForSharedPtr();
    TestForSharedPtr *tc2 = new TestForSharedPtr(1, 'a');

    shared_ptr shdptr1(tc1);
    shared_ptr shdptr2(tc2);
    shdptr1.swap(shdptr2);
    vector< shared_ptr > shdptrVector;
    shdptrVector.push_back(shdptr1);
    shdptrVector.push_back(shdptr2);
    cout << shdptr1.get()->cv << " " << shdptr1.get()->iv << endl;

    unique_ptr unqptr1(new TestForSharedPtr(1));
    unique_ptr unqptr2(new TestForSharedPtr(2));

    vector< unique_ptr > unqptrVector;
    unqptr1.swap(unqptr2);

    //unqptrVector.push_back(unqptr1);
    unqptrVector.push_back(move(unqptr2));

    if (unqptr1.get() == nullptr) {
        cout << "1 is null" << endl;
    }

    if (unqptr2.get() == nullptr) {
        cout << "2 is null" << endl;
    }
    // cout << unqptr1.get()->iv << " maybe not " << endl;


    tuple testTuple;
    for (int i = 0; i < tuple_size::value; i++) {
        // get(testTuple) = i; // this cannot
    }
    get<0>(testTuple) = 0;
    get<1>(testTuple) = 1;
    get<2>(testTuple) = 2;
    get<3>(testTuple) = 3;

    int fir, sec, thi, fou;
    tie(fir, sec, thi, ignore) = testTuple; // copy just one line

    tuple tuple1;
    tuple tuple2;

    auto tuple3 = tuple_cat(tuple1, tuple2);
    // auto : tuple

    return 0;
}
