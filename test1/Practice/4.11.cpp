#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include<string.h>


enum CPU_Rank { P1 = 1, P2, P3, P4, P5, P6, P7 };
class CPU
{
private:
	CPU_Rank rank;
	int frequency;
	float voltage;
public:
	CPU(){}
	CPU(CPU_Rank r, int f, float v)
	{
		rank = r;
		frequency = f;
		voltage = v;
		cout << "构造了一个CPU！" << endl;
	}
	~CPU() { cout << "析构了一个CPU！" << endl; }
	CPU_Rank GetRank() const { return rank; }
	int GetFrequency() const { return frequency; }
	float GetVoltage() const { return voltage; }

	void SetRank(CPU_Rank r) { rank = r; }
	void SetFrequency(int f) { frequency = f; }
	void SetVoltage(float v) { voltage = v; }

	void Run() { cout << "CPU开始运行！" << endl; }
	void Stop() { cout << "CPU停止运行！" << endl; }

};

class RAM {
private:
	int ram_capacity;
public:
	RAM(){}
	RAM(int c) {
		ram_capacity = c;
	}
	int GetCapacity() const { return ram_capacity; }
};

class CDRAM {
private:
	int cdram_capacity;
public:
	CDRAM(){}
	CDRAM(int c) {
		cdram_capacity = c;
	}
	int GetCapacity() const { return cdram_capacity; }
};

class Computer {
private:
	CPU cpu;
	RAM ram;
	CDRAM cdram;
public:
	Computer(){}
	Computer(CPU_Rank r, int f, float v, int r_c, int c_c):cpu(r,f,v),ram(r_c),cdram(c_c) {}
	void output() { cout << "cpu等级：" << cpu.GetRank() <<" cpu频率：" << cpu.GetFrequency() << "MHz cpu电压：" << cpu.GetVoltage() << "V " << " RAM容量：" << ram.GetCapacity() << "G " << " CDRAM容量：" << cdram.GetCapacity() << "M" << endl; }
};

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date() {}
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	void set() {cin >> year >> month >> day;}
	void output(){cout << "  年： " << year << "  月： " << month << "  日： " << day;}
};

class People {
private:
	int number;
	char sex;
	Date birthday;
	char ID[18];
public:
	People(){}
	People(int n, char s, int y,int m,int d, char id[18]):birthday(y,m,d) {
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
	void input() {
		cin >> number >> sex >> ID;
		birthday.set();

	}
	void output()
	{
		cout << "学号：" << number << "  性别： " << sex << "  身份证号： " << ID;
		birthday.output();
	}
	~People() { cout << "析构函数调用" << endl; }
};

void main()
{
	Computer c(P6, 300, 2.8, 200, 700 );
	c.output()   ;
}