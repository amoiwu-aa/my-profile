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
		cout << "����������ң�F�������ӣ�A),�༭��E����ɾ����D�����˳���Q��" << endl;
		cin >> input1;
		if (("F" == input1) || ("f" == input1))
		{
			cout << "����ѧ�ţ�";
			int id = -1;
			cin >> id;
			tmp = studentroot->find(id);
			if (tmp == NULL)
			{
				cout << "û�ҵ�" << endl;
				continue;
			}
			cout << "ѧ�ţ�" << tmp->getno();
			cout << "������";
			string name;
			if ((name = tmp->getname()) != "")
				cout << name << endl;
			else
				cout << "δ����";
			cout << "�ɼ���" << tmp->getscore() << endl;
		}
		else if ((input1 == "A") || (input1 == "a"))
		{
			cout << "�����������ɼ�:";
			cin >> input1 >> input2;
			tmp = new Student();
			tmp->edit(input1, input2);
			cout << "ѧ�ţ�" << studentroot->add(tmp) << endl;
		}
		else if ((input1 == "E") || (input1 == "e"))
		{
			cout << "����ѧ�ţ�";
			int id = 0;
			cin >> id;
			tmp = studentroot->find(id);
			if (tmp == NULL)
			{
				cout << "�պ�" << endl;
				continue;
			}
			cout << "���������³ɼ���";
			cin >> input1 >> input2;
			tmp->edit(input1, input2);
			cout << "���ĳɹ���" << endl;
		}
		else if ((input1 == "D") || (input1 == "d"))
		{
			cout << "����ѧ�ţ�";
			int id = 0;
			cin >> id;
			tmp = studentroot->find(id);			//�ҵ�ĳѧ��������ַ
			tmp->erase();							//����ɾ������
			cout << "�ѳɹ�ɾ��" << endl;
			delete tmp;
		}
		else if ((input1 == "Q") || (input1 == "q"))
		{
			break;
		}
		else
		{
			cout << "��������" << endl;
		}
	}
	delete studentroot;
	return 0;
}