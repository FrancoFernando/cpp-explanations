#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

/*
* Type of captures:
* []: no capture
* [x]: capture variable x by value
* [&x]: capture variable x by reference
* [=]: capture all variables by value
* [&]: capture all variables by reference
* [=,&x]: capture all variables by value, x by reference
* [&,=x]: capture all variables by reference, x by value
* [this]: capture data and member of the enclosing class
*/

struct AddNumber {
	AddNumber(int num) : x(num) {}
	int operator()(int y) const { return x + y; }

private:
	int x;
};

void TestLambda() {

	// create an instance of the functor class
	// and call it
	AddNumber add10(10);
	int x = add10(15);
	assert(x == 25);

	// create a lambda, assign lambda
	// to a variable and call it
	int value = 10;
	auto add10_lambda = [=](int a) { return value + a; };
	assert(add10_lambda(15) == 25);

	// generic lambda
	vector<int> v{ 1,2,3,4,5 };
	sort(v.begin(), v.end(), [](auto x, auto y)
	{
		return x > y;
	});
}