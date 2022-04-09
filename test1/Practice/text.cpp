#include <iostream>
using namespace std;
class Box {
	int width, length;
public:
	void const show();
	Box(int, int);
	int volume();
	static int height; //将height定义为静态整形数据成员
};
//在类体外定义构造函数，宽度width和
//长度length的缺省值均为10
Box::Box(int w=10,int len=10)
{
	width = w;length = len;
}
int Box::volume()
{
	return (height * width * length);
}
int Box::height = 10;
void main()
{
	Box a(15, 20);
	cout << a.height << endl; //输出对象a的高度height
	cout << Box::height << endl; //用另一种方式输出对象a的高度height
}