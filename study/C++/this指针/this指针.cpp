#include<iostream>
using namespace std;
class Point
{
public:
	Point(int x, int y) { X = x; Y = y; }
	Point() { X = 0; Y = 0; }
	void copy(Point& obj);
	void displayxy();
private:
	int X, Y;
};
void Point::copy(Point& obj)
{
	if (this != &obj) {							
		*this = obj;						
		cout << "this is wrong!" << endl;
	}
		
}
void Point::displayxy()
{
	cout << X << "";
	cout << Y << endl;
}
int main()
{
	Point obj1(10, 20), obj2;
	obj2.copy(obj1);				//this指针是对象obj2的指针
	obj1.displayxy();
	obj2.displayxy();
	return 0;
}