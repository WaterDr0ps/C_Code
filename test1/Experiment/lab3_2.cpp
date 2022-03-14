#include <iostream>
using namespace std;

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


int main() {
	double a, b, c;
	cin >> a; cin >> b; cin >> c;
	cout << Max1(a, b, c) << endl;
}