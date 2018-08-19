#include <iostream> 
#include <vector>

using namespace std;

int main() {

    // auto, lambda, range based loop, enum, nullptr
    {
        vector<int> t1;
        t1.push_back(33);
        auto iter = t1.begin(); 
        cout << *iter << endl;
    }

    auto lambdaTest = [](int i) { cout << i << endl; };

    lambdaTest(100);


    enum ITEMTYPE : short {
        WEAPON,
        EQUIPMENT,
        GEM = 10,
        DEFENSE,
    };

    short itemType = WEAPON;
    cout << itemType << endl;


    enum class CHARACTER_CLASS : short
    {
        WARRIOR = 1,
        MONK,
        FIGHTER,
    };


    CHARACTER_CLASS cc = CHARACTER_CLASS::MONK;
    cout << (int)cc << endl; 

    int* ggg = nullptr;





    return 0;
}

