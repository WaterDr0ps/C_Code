#include <iostream>
using namespace std;
class Box {
	int width, length;
public:
	void const show();
	Box(int, int);
	int volume();
	static int height; //��height����Ϊ��̬�������ݳ�Ա
};
//�������ⶨ�幹�캯�������width��
//����length��ȱʡֵ��Ϊ10
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
	cout << a.height << endl; //�������a�ĸ߶�height
	cout << Box::height << endl; //����һ�ַ�ʽ�������a�ĸ߶�height
}