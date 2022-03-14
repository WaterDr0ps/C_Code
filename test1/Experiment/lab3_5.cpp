#include <iostream>
using namespace std;

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

int main() {
	int a = 2;
	int b = 3;
	swap1(a, b);
	cout << a << b << endl;
	swap2(&a, &b);
	cout << a << b << endl;
	swap3(a, b);
	cout << a << b << endl;
}