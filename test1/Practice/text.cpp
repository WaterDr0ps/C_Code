#include <iostream>
using namespace std;
class XA {
	int a;
public:
	static int b;
	XA(int aa) :a(aa) { b++; }
	~XA() {}
	int get() { return a; }
};
int XA::b = 0;
int main() {
	XA d1(2), d2(3);
	cout << d1.b << endl;
	cout << XA::b << endl;

	return  0;
}