#include <iostream>
#include <iomanip>
using namespace std;

float Convert(float TempFer) {
	return (TempFer - 32) * 5 / 9;
}

int main() {
	float T;
	cin >> T;
	cout << setprecision(3)<<Convert(T);
}