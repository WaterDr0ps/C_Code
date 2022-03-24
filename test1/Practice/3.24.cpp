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
	cout << "请输入矩形的长度：";
	cin >> lg;
	cout << "请输入矩形的宽度：";
	cin >> wid;
	Rectangle rec=Rectangle(lg,wid);
	cout << "长为" << lg << "宽为" << wid << "的矩形的面积为：" << rec.GetArea();
}