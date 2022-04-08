

#include "text.h"
void main()
{
X x;
Z z;
z.f(&x);
}
/*
定义类X、Y、Z，函数h(X*)，满足：类X有私有成员i（int），Y的成员函数void g(X*)是X的友元函数，实现对X的成员i加1，
类Z是类X的友元类，其成员函数void f(X*)实现对X的成员i加5，函数void h(X*)是X的友元函数，实现对X的成员i加10。
在一个文件中定义和实现类，在另一个文件中实现main()函数。
*/


