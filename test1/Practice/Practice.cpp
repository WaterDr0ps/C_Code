#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string.h>


class Date {
private:
	int year;
	int month;
	int day;
public:
	Date(){}
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	void set() {
		cin >> year >> month >> day;
	}
	void output()
	{
		cout << "  年： " << year << "  月： " << month << "  日： " << day;
	}
};

class People {
private:	
	int number;
	char sex;
	Date birthday;
	char ID[18];
public:
	People(){}
	People(int n, char s, int y, int m, int d, char id[18]) :birthday(y, m, d) {
		number = n;
		sex = s;
		strcpy(ID, id);
	}
	People(People& p) {
		number = p.number;
		sex = p.sex;
		birthday = p.birthday;
		strcpy(ID, p.ID);
	}
	void input(){
		cin >> number >> sex >> ID;
		birthday.set();
		
	}
	void output()
	{
		cout << "学号：" << number << "  性别： " << sex << "  身份证号： " << ID;
		birthday.output();
	}
	~People() {}
};



int main() {
	Date mybirthday;

	People my;

	my.input();

	People  zhaoxiaojun(my);

	cout << " zhaoxiaojun information is:" << endl;

	cout << "注意性别中m为男，f为女" << endl;

	zhaoxiaojun.output();

	getchar();

	return 0;
}