#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Date
{
public:
	Date(int year = 2018, int month = 1, int day = 1) :_year(year), _month(month), _day(day){}

	bool operator < (const Date& d) const
	{
		return (_year < d._year || (_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day));
	}

	bool operator > (const Date& d) const
	{
		return (_year > d._year || (_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day));
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		cout << d._year << " /" << d._month << " /" << d._day << endl;
		return _cout;
	}

private:
	int _year;
	int _month;
	int _day;
};

void Testpriority_queue1()
{
	// ��ѣ���Ҫ�û����Զ����������ṩ<������
	priority_queue<Date> q1;
	q1.push(Date(2018, 10, 29));
	q1.push(Date(2018, 10, 28));
	q1.push(Date(2018, 10, 30));

	cout << q1.top() << endl;

	// ���Ҫ����С�ѣ���Ҫ�û��ṩ>������
	priority_queue<Date, vector<Date>, greater<Date>> q2;
	q2.push(Date(2018, 10, 29));
	q2.push(Date(2018, 10, 28));
	q2.push(Date(2018, 10, 30));

	cout << q2.top() << endl;
}

class Less
{
public:
	bool operator()(const Date* pLeft, const Date* pRight)
	{
		return *pLeft < *pRight;
	}
};

void Testpriority_queue2()
{
	// �Լ����ƱȽϵĹ���?
	priority_queue<Date*, vector<Date*>, Less> q;
	q.push(&Date(2018, 10, 29));
	q.push(&Date(2018, 10, 28));
	q.push(&Date(2018, 10, 30));

	cout << *q.top() << endl;
}

int main()
{
	//����
	//Ĭ������£��������Ǵ�ѣ���ײ㰴��С�ںűȽ�
	vector<int> v = { 3, 6, 1, 6, 8, 4, 6, 9, 10 };
	priority_queue<int> q1;

	for (auto& e : v)
	{
		q1.push(e);
	}
	cout << q1.top() << endl;

	//���Ҫ����С�ѣ���������ģ���������greater�ȽϷ�ʽ
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.top() << endl;

	//����Զ�������ʱ������ > ���� <  
	Testpriority_queue1();

	//�Ƚ�������
	Testpriority_queue2();

	system("pause");
	return 0;
}