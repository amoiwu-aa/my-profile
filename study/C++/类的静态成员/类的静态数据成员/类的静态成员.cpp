#include<iostream>
using namespace std;
class Point
{
public:
	static int countP;
	Point(int = 0, int = 0);
	~Point();
private:
	int X, Y;
};
Point::Point(int x, int y)
{
	X = x;
	Y = y;
	cout << "Constructor is called!" << endl;
	cout << X <<"和" << Y << endl;
	countP++;
}
Point::~Point()
{
	cout << "Destructor is called!" << endl;
	countP--;
	cout << "现在对象数是：" << countP << endl;
}
int Point::countP = 0;
int main()
{
	Point A(4, 5);
	cout << "现在对象数是：" << A.countP << endl;
	Point B(7, 8);
	cout << "现在对象数是：" << Point::countP << endl;
	return 0;
}