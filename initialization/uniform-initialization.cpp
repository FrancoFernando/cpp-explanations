#include <iostream>
#include <vector>

using namespace std;

void TestInitialization() {

	//Uniform initialization: error
	//char c1{1024};
	//char c2 = {1024};
	//Classic initialization: only warning
	char c1(1024);
	char c2 = 1024;
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;

	//Uniform initialization: error
	//int i1{2.913};
	//int i2 = {2.913};
	//Classic initialization: only warning
	int i1(2.913);
	int i2 = 2.913;
	cout << "i1: " << i1 << endl;
	cout << "i2: " << i2 << endl;
}

int main() {
	TestInitialization();
}