#include<iostream>
using namespace std;
class Circle {
private:
	float Radius;
public:
	Circle(float r):Radius(r){}
	float GetArea() {
		return 3.14 * Radius * Radius;
	}
};
int main() {
	Circle c(10);
	cout<<c.GetArea();
}