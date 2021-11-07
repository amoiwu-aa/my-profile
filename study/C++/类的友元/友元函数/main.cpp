#include<iostream>
#include<cmath>
using namespace std;
class Point;
class Circle;
class Circle
{
public:
	Circle() {};
	Circle(double c) { Z = c; }
	friend double jian(Point& a, Circle& b);
private:
	int Z;
	int X, C;
};
class Point
{
public:
	Point() {};
	Point(double x, double y) { X = x; Y = y; }
	friend double length(Point& a, Point& b);
	friend double jian(Point& a, Circle& b);
private:
	int X;
	int Y;
};


double length(Point& a, Point& b)
{
	double dx = a.X - b.X;
	double dy = a.Y - b.Y;
	return sqrt(dx * dx + dy * dy);
}
double jian(Point & a, Circle& c)
{
	double dc = a.X - c.C;
	return dc;
}

int main()
{
	Circle a;
	Point t;
	jian(t, a);
	return 0;
}