#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

void TestZero() {

	auto a = 0;
	int* b = 0;
	cout << typeid(a).name() << endl;  //int

	auto res = a + b;  //pointer arithmetic applies
	cout << "res: " << res << endl;
	cout << typeid(res).name() << endl; //int* 
	cout << endl;
}

std::string overloadTest(char*) {
	return "char*";
}

std::string overloadTest(int) {
	return "int";
}

void TestMacro() {

	auto a = NULL;
	int* b = NULL;
	cout << typeid(a).name() << endl; // int
	cout << typeid(NULL).name() << endl; // int
	cout << "overloadTest(NULL) = " << overloadTest(NULL) << endl;
	cout << endl;
}

template<class P >
void testTemplate(P p) {
	int* a = p;
}

void TestNullptr() {

	int* a = 0;
	int* b = NULL;
	int* c = nullptr;

	//invalid conversion from int to int*
	//testTemplate(0);
	//testTemplate(NULL);
	testTemplate(nullptr);

	cout << endl;
}

void TestNullptrFinal() {

	int* pi = nullptr;    // OK
	// int i= nullptr;    // cannot convert std::nullptr_t to int

	// calls int
	cout << "overloadTest(0) = " << overloadTest(0) << endl;

	// calls char*
	cout << "overloadTest(static_cast<char*>(0))= " << overloadTest(static_cast<char*>(0)) << endl;

	// calls char*
	cout << "overloadTest(nullptr)= " << overloadTest(nullptr) << endl;

	// call of overloaded ‘overloadTest(NULL)’ is ambiguous
	cout << "overloadTest(NULL)= " << overloadTest(NULL) << endl;

	cout << endl;
}


int main() {
	
	TestZero();
	TestNullptr();
	TestMacro();
	TestNullptr();
	TestNullptrFinal();
}