#include <any>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void TestAny() {

	// initialization with an object:
	any a1(10); // int

	// make_any
	any a2 = make_any<string>("Any string");

	// container with any
	vector<any> v{true, 2021, string("any"), 2.78};
                                                    
	cout << v[1].type().name() << '\n'; // i

	try {                                                  
		cout << any_cast<int>(v[1]) << '\n'; // 2021  
	}
	catch(const bad_any_cast& e) {
		cout << e.what() << '\n';
	}   
}

int main() {
	TestAny();
}