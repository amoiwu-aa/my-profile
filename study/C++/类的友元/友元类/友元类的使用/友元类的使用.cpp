#include <iostream>
using namespace std;
class student
{
public:
    friend class teacher;           //teacher是student的友元类
    protected:
        student();
private:
    int number, score;              //学号，成绩
};
class teacher
{
public:
    teacher(int i, int j);
    void display();
private:
    student a;
};
student::student()
{}
teacher::teacher(int i, int j)
{
    a.number = i;
    a.score = j;
}
void teacher::display()
{
    cout << "No=" << a.number << "";
    cout << "  score=" << a.score << endl;
}

int main()
{
    teacher t1(1001, 89), t2(1002, 78);
    cout << "第1个学生信息 ";
    t1.display();
    cout << "第2个学生信息 ";
    t2.display();
    return 0;
}
