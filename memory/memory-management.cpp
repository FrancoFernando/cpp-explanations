#include <iostream>

using namespace std;

class Point {
	int x, y;
public:
	//necessary for []
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}
};

void OperatorNew() {
	int* x = new int(3);
	double* d = new double(12.3);
	Point* p = new Point(1.0, 2.0);
}

void OperatorNewArray() {
	double* d = new double[5];
	Point* p = new Point[10];
}

void PlacementNew() {

	char* memory = new char[sizeof(Point)]; // allocate std::size_t 
	Point* p = new(memory) Point; // instantiate point in memory
}

void OperatorDelete() {
	Point* p = new Point();
	delete p;
}

void OperatorDeleteArray() {
	Point* p = new Point[10];
	delete[] p;
}

void PlacementDelete() {
	// placement new
	char* memory = new char[sizeof(Point)];
	Point* p = new(memory) Point;
	// destructor
	p->~Point();
	// placement delete
	operator delete(p, memory);
}

void TestMemory() {
	OperatorNew();
	OperatorNewArray();
	PlacementNew();
	OperatorDelete();
	OperatorDeleteArray();
	PlacementDelete();
}