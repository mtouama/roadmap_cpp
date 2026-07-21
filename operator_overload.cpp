#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b) {}

    Point operator+(const Point& p) {
        return Point(x + p.x, y + p.y);
    }
};
//  g++ operator_overload.cpp -o operator_overload
int main() {
    Point p1(2, 3);
    Point p2(4, 5);

    Point p3 = p1 + p2;

    cout << p3.x << ", " << p3.y << endl;
    return 0;
}