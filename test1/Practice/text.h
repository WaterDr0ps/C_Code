#ifndef MY_X_Y_Z_H
class X;
class Y {
public:
	void g(X*);//1
};
class X
{
private:
	int i;//2
public:
	X() { i = 0; }
	friend void Y::g(X*);//3
	friend class Z;//4
	friend void h(X*);//5
};
void h(X* x) { x->i = +10; }
void Y::g(X* x)//6
{
	x->i++;
}
class Z {
public:
	void f(X* x)//7
	{
		x->i += 5;
	}
};
#endif // MY_X_Y_Z_H