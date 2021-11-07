#include <iostream>
using namespace std;
class Point
{
public:
    Point(int = 0, int = 0);
    static void displayxy(Point p);
private:
    int X, Y;
};
Point::Point(int x, int y)
{
    X = x;
    Y = y;
}
void Point::displayxy(Point p)
{
    cout << "("<<p.X << "," << p.Y << ")" << endl;
}
int main()
{
    Point A(4, 5);
    cout << "第1个点的位置是：";
    Point::displayxy(A);
    Point B(7, 8);
    cout << "第2个点的位置是：";
    Point::displayxy(B);
    return 0;
}
