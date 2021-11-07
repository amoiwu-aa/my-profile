
class Student
{
	int no;
	string name;
	float score;
	Student* per;
	Student* next;
public:
	Student();
	Student *find(int i_no);
	void edit(string i_newname, float i_score);
	void erase();
	int add(Student* i_newStudent);
	int getno();
	string getname();
	float getscore();
	static int maxno;
};
