#include <iostream>
using namespace std;
class CE {
private:
	int a, b;
	int getmin() { return (a < b ? a : b); }
public:
	int c;
	void SetValue(int x1, int x2, int x3) {
		a = x1;b = x2; c = x3;
	};
	int GetMin();
};
int GetMin() { //´íÎó
	int d = getmin();
	return (d < c ? d : c);
}