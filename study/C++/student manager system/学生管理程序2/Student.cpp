#include "Student.h"
Student::Student()
{

	//  maxno = 0;
	no = 0;
	score = 0.0f;
}
Student::~Student()
{
	score = 0.0;
	per = NULL;
	next = NULL;
}

Student* Student::find(int i_no)
{
	if (i_no == no)					//如果是类当前的数返回本身，也就是已存在同号的，或者输入过的值
		return this;
	if (next != NULL)				//同时如果下一个结点不为空，则到下一个结点寻找，返回下一个结点的寻找
		return next->find(i_no);    //指向下个指针结点的find(i_no)（选择运算符）
	//return NULL;
	return nullptr;
}


void Student::edit(string i_name, float i_score)
{
	if (i_name == "")
		return;												//如果学生姓名为空，返回，不往下面跑了，函数不需要返回值
	name = i_name;											//如果不是，则把输入的名字分数赋值
	score = i_score;
}


void Student::erase()
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


int Student::add(Student* i_newStudent)
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
	return 0;
}


string Student::getname()
{
	return name;
}


float Student::getscore()
{
	return score;
}



int Student::getno()
{
	return no;
}
