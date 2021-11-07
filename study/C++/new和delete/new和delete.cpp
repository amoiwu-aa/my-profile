#include <iostream>
using namespace std;
class Heapclass
{
public:
	Heapclass();
	~Heapclass();
private:
	int i;
};
Heapclass::Heapclass()
{
	cout << "Default Constructor is called." << endl;
}
Heapclass::~Heapclass()
{
	cout << "Destructor is called." << endl;
}
int main()
{
	Heapclass* ptr;
	ptr = new Heapclass[2];
	if (!ptr)
	{
		cout << "Out of Memory!" << endl;
		return 0;
	}
	cout << "Exit main" << endl;
	delete[]ptr;
	return 0;
}
