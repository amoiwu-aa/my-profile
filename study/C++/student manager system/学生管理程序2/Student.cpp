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
	if (i_no == no)					//������൱ǰ�������ر���Ҳ�����Ѵ���ͬ�ŵģ������������ֵ
		return this;
	if (next != NULL)				//ͬʱ�����һ����㲻Ϊ�գ�����һ�����Ѱ�ң�������һ������Ѱ��
		return next->find(i_no);    //ָ���¸�ָ�����find(i_no)��ѡ���������
	//return NULL;
	return nullptr;
}


void Student::edit(string i_name, float i_score)
{
	if (i_name == "")
		return;												//���ѧ������Ϊ�գ����أ������������ˣ���������Ҫ����ֵ
	name = i_name;											//������ǣ������������ַ�����ֵ
	score = i_score;
}


void Student::erase()
{
	if (no < 0)
		return;
	if (per != NULL)					//��ǰָ���㲻Ϊ��
		per->next = next;				//����һ�����ָ���ַ��ֵ������һ��ָ���ַ��ֱ��������ǰ���
	if (next != NULL)
		next->per = per;				//����һ�������ָ���ַ��ֵ��ǰ��ָ���׵�ַ��per��ָ����һ�����ָ��a
	next = NULL;
	per = NULL;
}


int Student::add(Student* i_newStudent)
{
	int no = maxno + 1;							//����ѧ��
	while (true)
	{
		if (NULL == find(no))				//�ҵ�һ����ֵ�ģ�������ѭ�������ѧ�Ŵ��ڣ��ͼ�1����һ��ѧ��	
			break;
		no = no + 1;
	}
	Student* tmp = this;					//����һ��ָ��tmp������this��Ѱ�� ����Ҫ��ֵ��ǰһ���ָࣩ�봫��tmp
	while (true)
	{
		if (tmp->next == NULL)				//�����ʱ���ݵ���һ��ָ��Ϊ�գ��������������Ϊ�գ������һ��ָ�븳ֵ����ʱָ�루Ҳ����ͷ��
			break;
		tmp = tmp->next;
	}
	tmp->next = i_newStudent;				//����ʱָ�루Ҳ����������һ�������nextΪ��ʱ���Ͱ�i_newStudent���׵�ַ������ʱ��ַ��next
	i_newStudent->next = NULL;			//��i_newStudent����һ������ַ��ֵΪ��
	i_newStudent->per = tmp;			//��tmp���׵�ַ��i_newStudent������Ѱ�ҵ���һ���࣬����
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
