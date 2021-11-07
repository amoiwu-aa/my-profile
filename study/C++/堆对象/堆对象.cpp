#include<iostream>
using namespace std;
class Heapclass {
public:
	Heapclass(int x);
	Heapclass();
	~Heapclass();
private:
	int i;
};
Heapclass::Heapclass(int x)
{
	i = x;
	cout << "Constructor is called." << i << endl;
}
Heapclass::Heapclass()
{
	cout << "Default Constructor is called." << endl;
}
Heapclass::~Heapclass()
{
	cout << "Destructor is  called." << endl;
}
int main()
{
	Heapclass* pa1, * pa2;
	pa1 = new Heapclass[3]{1,2,3};
	pa2 = new Heapclass(5);
	if (pa1 || pa2)
	{
		cout << "Out of Memory!" << endl;
		return 0;
	}
	cout << "Exit main" << endl;
	delete[] pa1;
	delete pa2;
	return 0;
}