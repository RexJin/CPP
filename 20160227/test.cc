 ///
 /// @file    test.cc
 /// @author  JinXin(xinge1231@qq.com)
 /// @date    2016-02-27 20:03:37
 ///
 
#include <iostream>
using namespace std;

int main()
{
	int a=5,d=6;
	int & b=a;
	b=d;
	int & c=b;
	a=8;
	cout<<"c="<<c<<"b="<<b<<endl;
	return 0;
}
