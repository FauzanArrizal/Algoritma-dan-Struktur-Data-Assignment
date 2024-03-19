#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    // Membuat objek 
    Point p1;
    p1.x = 10;
    p1.y = 30;

    // Koordinat p1
    cout << "Point koordinat: (" << p1.x << ", " << p1.y << ")" << endl;

    return 0;
}
