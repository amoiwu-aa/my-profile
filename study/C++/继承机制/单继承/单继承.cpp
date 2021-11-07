#include<iostream>
using namespace std;
class Point {
public:
	void setxy(int myx, int myy) { X = myx; Y = myy; }
	void movexy(int x, int y) { X+= x; Y += y; }
protected:
	int X, Y;
private:
};
class Circle :private Point
{
public:
	void setr(int myx, int myy, int myr)
	{
		setxy(myx, myy); R = myr;
	}
	void movexy(int , int );
	void display();
protected:
		int R;
};
void Circle::movexy(int x, int y)
{
	Point::movexy(x, y);
}
void Circle::display()
{
	cout << "The position of center is:";
	cout <<"("<<X<<","<<Y<<")"<<endl;
	cout <<"The radius of Circle is"<<R<<endl;
}
class Cylinder :public Circle
{
protected:
	int H;
};
int main()
{
	Circle	c;
	c.setr(4, 5, 6);
	cout << "The start data of Circle:" << endl;
	c.display();
	c.movexy(7, 8);
	cout << "The new data of Circle:" << endl;
	c.display();
	return 0;
}
