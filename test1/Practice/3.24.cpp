#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string.h>

class Rectangle {
private:
	float lg;
	float wid;
public:
	Rectangle(){}
	Rectangle(float l, float w) {
		lg = l;
		wid = w;
	}
	int GetArea() {
		return lg * wid;
	}
};

int main() {
	float lg, wid;
	cout << "��������εĳ��ȣ�";
	cin >> lg;
	cout << "��������εĿ�ȣ�";
	cin >> wid;
	Rectangle rec=Rectangle(lg,wid);
	cout << "��Ϊ" << lg << "��Ϊ" << wid << "�ľ��ε����Ϊ��" << rec.GetArea();
}