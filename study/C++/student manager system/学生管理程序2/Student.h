#pragma once
#include"head.h"
class Student
{
	int no;
	string name;
	float score;
	Student* per;
	Student* next;
	static int maxno;
public:
	Student();
	~Student();
	Student* find(int i_no);
	void edit(string i_newname, float i_socre);
	void erase();
	int add(Student* i_newStudent);
	string getname();
	float getscore();
	int getno();
};

