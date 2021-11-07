#include <iostream>
#include<string>
using namespace std;
class Student				//类的定义
{
	int no;					//定义学生的学号
	string name;			//学生的姓名
	float score;			//学生的分数
	Student* per;			//当前结点指针
	Student* next;			//下一个结点指针
public:
	Student();				//构造函数
	Student* find(int i_no);			//查找指定学号的学生
	void edit(string i_newname, float i_score);			//修改学生的信息
	void erase();										//删除指定学号的学生
	int add(Student* i_newStudent);						//增加学生
	int getno();										//获得学生的学号
	string getname();									//获得学生的名字
	float getscore();									//获得学生的成绩
	static int maxno;									//当前最大学号
};
Student::Student()				//构造函数
{
	score = 0.0;
	per = NULL;
	next = NULL;
}
Student* Student::find(int i_no)   //查找指定学号的学生函数
{
	if (i_no == no)					//如果是类当前的数返回本身，也就是已存在同号的，或者输入过的值
		return this;
	if (next != NULL)				//同时如果下一个结点不为空，则到下一个结点寻找，返回下一个结点的寻找
		return next->find(i_no);    //指向下个指针结点的find(i_no)（选择运算符）
	return NULL;
}
void Student::edit(string i_name, float i_score)			//修改学生的名字函数
{
	if (i_name == "")
		return;												//如果学生姓名为空，返回，不往下面跑了，函数不需要返回值
	name = i_name;											//如果不是，则把输入的名字分数赋值
	score = i_score;										
}

int Student::add(Student* i_newStudent)			//增加学生函数,返回学号
{
	int no = maxno + 1;							//定义学号
	while (true)
	{
		if (NULL == find(no))				//找到一个空值的，才跳出循环，如果学号存在，就加1得另一个学号	
			break;
		no = no + 1;
	}
	Student* tmp = this;					//创建一个指针tmp，把类this（寻找 到了要赋值的前一个类）指针传给tmp
	while (true)
	{
		if (tmp->next == NULL)				//如果临时数据的下一个指针为空，则跳出，如果不为空，则把下一个指针赋值给临时指针（也就是头）
			break;
		tmp = tmp->next;					
	}
	tmp->next = i_newStudent;				//当临时指针（也就是类的最后一个）里的next为空时，就把i_newStudent的首地址传给临时地址的next
	i_newStudent->next = NULL;			//给i_newStudent的下一个结点地址赋值为空
	i_newStudent->per = tmp;			//把tmp的首地址给i_newStudent，可以寻找到上一个类，链表
	i_newStudent->no = no;
	return no;
}
void Student::erase()			//删除指定学号的学生函数
{
	if (no < 0)					
		return;
	if (per != NULL)					//当前指针结点不为空
		per->next = next;				//把上一个结点指针地址赋值给类下一个指针地址，直接跳过当前结点
	if (next != NULL)
		next->per = per;				//把下一个结点首指针地址赋值当前类指针首地址，per是指向上一个类的指针a
	next = NULL;
	per = NULL;

}
int Student::getno() { return no; }					//获得学生的学号
string Student::getname(){ return name; }			//获得学生的名字
float Student::getscore(){ return score; }			//获得学生的成绩
int Student::maxno = 1000;
int main()
{
	Student* studentroot = new Student();
	string input1;
	float input2;
	Student* tmp = NULL;
	while (true)
	{
		cout << "输入命令：查找（F），增加（A),编辑（E），删除（D），退出（Q）" << endl;
		cin >> input1;
		if (("F" == input1) || ("f" == input1))
		{
			cout << "输入学号：";
			int id = -1;
			cin >> id;
			tmp = studentroot->find(id);
			if (tmp == NULL)
			{
				cout << "没找到" << endl;
				continue;
			}
			cout << "学号：" << tmp->getno();
			cout << "姓名：";
			string name;
			if ((name = tmp->getname()) != "")
				cout << name << endl;
			else
				cout << "未输入";
			cout << "成绩：" << tmp->getscore() << endl;
		}
		else if ((input1 == "A") || (input1 == "a"))
		{
			cout << "输入姓名，成绩:";
			cin >> input1 >> input2;
			tmp = new Student();
			tmp->edit(input1, input2);
			cout << "学号：" << studentroot->add(tmp) << endl;
		}
		else if ((input1 == "E") || (input1 == "e"))
		{
			cout << "输入学号：";
			int id = 0;
			cin >> id;
			tmp = studentroot->find(id);
			if (tmp == NULL)
			{
				cout << "空号" << endl;
				continue;
			}
			cout << "新姓名，新成绩：";
			cin >> input1 >> input2;
			tmp->edit(input1, input2);
			cout << "更改成功。"<<endl;
		}
		else if ((input1 == "D") || (input1 == "d"))
		{
			cout << "输入学号：";
			int id = 0;
			cin >> id;
			tmp = studentroot->find(id);			//找到某学号类对象地址
			tmp->erase();							//运行删除操作
			cout << "已成功删除" << endl;
			delete tmp;
		}
		else if ((input1 == "Q") || (input1 == "q"))
		{
			break;
		}
		else
		{
			cout << "输入有误！" << endl;
		}
	}
	delete studentroot;
	return 0;
}
