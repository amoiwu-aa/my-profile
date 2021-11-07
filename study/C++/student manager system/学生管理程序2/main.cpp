#include "Student.h"
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
			cout << "更改成功。" << endl;
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