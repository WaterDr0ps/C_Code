
#include<math.h>
#include <iostream>
using namespace std;
float Convert(float TempFer) {
	return (TempFer - 32) * 5 / 9;
}

int Max1(int a, int b) {
	return a > b ? a : b;
}

int Max1(int a, int b, int c) {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

double Max1(double a, double b) {
	return a > b ? a : b;
}

double Max1(double a, double b, double c) {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

void swap1(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap2(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap3(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}


int main()
{
	/*
	float T;
	cin >> T;
	cout << Convert(T);

	double a, b, c;
	cin >> a; cin >> b; cin >> c;
	cout<<Max1(a, b, c)<<endl;

	int x, y;
	cout << "请输入两个整数：";
	cin >> x; cin >> y;
	cout<<pow(x, y)<<endl;

	cout << fib(5) << endl;

	int a = 2;
	int b = 3;
	swap1(a, b);
	cout << a << b << endl;
	swap2(&a, &b);
	cout << a << b << endl;
	swap3(a, b);
	cout << a << b << endl;
	*/
}


