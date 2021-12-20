#include <memory>

using namespace std;


void TestSmartPointers() {

    unique_ptr<int> up1(new int(2011));
    //std::unique_ptr<int> up2 = up1;            // ERROR
    unique_ptr<int> up3 = move(up1); // OK
}

