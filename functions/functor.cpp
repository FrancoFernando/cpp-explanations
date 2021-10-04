#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

struct AddNumber {
    AddNumber(int num) : x(num) {}
	int operator()(int y) const { return x + y; }

private:
	int x;
};

void TestFunctor() {

	// create an instance of the functor class
	// and call it
	AddNumber add10(10);
	int x = add10(15); 
	assert(x == 25); 

	vector<int> in{1,2,3,4,5}; 
	vector<int> out(in.size());

	// Pass a function object to std::transform, which calls it on every  
	// element of the input and stores the result to the output
	transform(in.begin(), in.end(), out.begin(), AddNumber(1));
	for (int i = 0; i < in.size(); ++i) {
		assert(out[i] == in[i] + 1);
	}
}