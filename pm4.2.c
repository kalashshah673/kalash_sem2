#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int xVal = 0, int yVal = 0) {
        x = xVal;
        y = yVal;
    }

    // Chainable move function
    Point& move(int dx, int dy) {
        this->x += dx;
        this->y += dy;
        return *this;   // return current object
    }

    // Display function
    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // Friend function to modify using pointer
    friend void modifyPoint(Point* p);
};

// Pass-by-reference using pointer
void modifyPoint(Point* p) {
    p->move(10, 10);  // modify using pointer

}

int main() {
    Point p(1, 2);

    cout << "Initial Point: ";
    p.display();

    // Chaining move()
    p.move(2, 3).move(-1, 4);

    cout << "After Chained Moves: ";
    p.display();

    // Pass by reference using pointer
    modifyPoint(&p);

    cout << "After Pointer Modification: ";
    p.display();

    return 0;
}
