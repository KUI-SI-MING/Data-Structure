#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//2018.11.21 ��Ͷ����ϲ���
//
//��Ĵ�С
//class C1
//{
//public:
//	void F1(){}
//private:
//	int _d;
//};
//
//class C2
//{
//public:
//
//	void F1(){}
//};
//
//class C3
//{
//};
//
//int main()
//{
//	cout << "C1: " << sizeof(C1) << " " << "C2: " << sizeof(C2) << " " << "C3: " << sizeof(C3) << endl;
//	system("pause");
//	return 0;
//}

////ƫ����
//class Student
//{
//public:
//	Student(string n, int a, char s) :name(n), age(a), sex(s){}
//	void show();
//
//	string name;
//	int age;
//	char sex;
//};
//
//void Student::show()
//{
//		cout << "name:" << name << endl <<
//			"age:" << age << endl <<
//			"sex:" << sex << endl;
//}
//int main()
//{
//	Student s1("Li Hua", 20, 'M');
//	s1.show();
//
//	//����ƫ����
//	//1.��Ա��ַ - ��ĵ�ַ
//	int offset_num = (int)&(s1.sex) - (int)&s1;
//	cout << "offset_num: " << offset_num << endl;
//
//	//��offsetof()
//	cout << "offset_num: " << offsetof(Student, sex) << endl;
//	system("pause");
//	return 0;
//}

////�жϴ�С��
////int CheckSystem()
////{
////	union Check{
////		int i;
////		char ch;
////	}uc;
////	uc.i = 1;
////	return uc.ch;
////}
////int CheckSystem()
////{
////	int i = 1;
////	if (*((char*)(&i)) == 1)
////	{
////		return 1;
////	}
////	return 0;
////}
typedef unsigned char byte;
int CheckSystem()
{
	unsigned int d = 0;
	unsigned int* p = &d;
	*((byte*)p) = 0xf;
	if (0xf == d)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int ret = CheckSystem();
	if (ret == 1){
		cout << "С��ģʽ" << endl;
	}
	else
		cout << "���ģʽ" << endl;
	system("pause");
	return 0;
}