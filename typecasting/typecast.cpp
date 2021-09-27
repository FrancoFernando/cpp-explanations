#include <iostream>

using namespace std;

class Base {};
class Derived : public Base {};

enum class Color {
	red,
	blue,
	green
};

class A {
public:
	virtual ~A() = default;
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};
class E : public B, public C {};

void TestDynamicCasting() {
	A* a = nullptr;
	B* b = nullptr;
	C* c = nullptr;
	D* d = nullptr;
	E e;

	a = dynamic_cast<A*> (&e);// upcast
	a = &e;// upcast
	b = dynamic_cast<B*>(a);// downcast
	c = dynamic_cast<C*>(b);// crosscast
	d = dynamic_cast<D*>(a);// downcast
}


void TestConstCasting() {

	int i = 11;
	const int* constI = const_cast<const int*>(&i); //Const int pointer for an int
	int* nonConstI = const_cast<int*>(constI); //Casting to int pointer
	*nonConstI = 9;

	cout << "i: " << i << endl;//i = 9
	cout << "typeid(constI).name(): " << typeid(constI).name() << endl;//int const *
	cout << "typeid(nonConstI).name(): " << typeid(nonConstI).name() << endl;//int *
}

void TestReinterpretCast() {

	double* d = new double(8.5);
	cout << *d << endl;

	void* v = reinterpret_cast<void*>(d);

	double* d1 = reinterpret_cast<double*>(v);
	cout << *d << endl;//d = 8.5

}

void TestStaticCast() {

	Base* a = nullptr;
	Derived* b = nullptr;

	a = static_cast<Base*>(b); //upcast               
	b = static_cast<Derived*>(a);  //downcast

	int i = 3;
	Color col = static_cast<Color>(i);
	cout << "i: " << i << endl;
	cout << "col: " << static_cast<int>(col) << endl;

	int i2 = static_cast<int>(12.11);
	cout << "i2: " << i2 << endl;

	cout << endl;
}

void TestCStyle() {
	char c = 'a';  //1 byte
	int* z = (int*)&c;  //4 bytes
	//*z = 10;  //runtime error: stack corruption

	double d = 3.1;
	auto p = (long*)&d;
	auto q = (long long*)&d;

	//d = 2, but *p and *q no
	cout << d << ' ' << *p << ' ' << *q << '\n';

	cout << endl;
}


int main() {

	TestCStyle();
	TestStaticCast();
	TestDynamicCasting();
	TestConstCasting();
	TestReinterpretCast();
}
