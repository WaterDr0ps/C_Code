#include <iostream>
using namespace std;

class Dog {
private:
	int age;
	int weight;

public:
	void setDog(int a, int w) {
		age = a;
		weight = w;
	}

	void printDog() {
		cout << "age=" << age << endl;
		cout << "weigth=" << weight << endl;
	}
};

int main() {
	Dog d;
	d.setDog(20, 50);
	d.printDog();
}