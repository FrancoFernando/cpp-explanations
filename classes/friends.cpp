#include <iostream>

using namespace std;

class Point {
    int x, y;

public:
    Point() : x(0), y(0) {}

    Point(int _x, int _y) : x(_x), y(_y) {}

    void PrintPoint();

    friend void SetPoint(Point& p, int _x, int _y);
};

// This is a member function that print the point.
void Point::PrintPoint() {
    cout << "x = " << x << ",y = " << y << endl;
}

// The implementation of our friend function
void SetPoint(Point& p, int _x, int _y) {
    p.x = _x;
    p.y = _y;
}

void TestFriends() {

    Point p;
    p.PrintPoint();
    SetPoint(p, 1, 3);
    p.PrintPoint();
}