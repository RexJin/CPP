 ///
 /// @file    memory_area.cc
 /// @author  JinXin(xinge1231@qq.com)
 /// @date    2016-02-26 19:48:47
 ///
 
#include <iostream>
#include <cstring>
using namespace std;

int a=0;
char *p1;

int main()
{
	int b;
	char s[]="abc";
	char *p2="123456";
	char *p3="123456";
	static int c=0;
	p1=new char[10];
	strcpy(p1,"123456");//拷贝值，非指向

	cout<<hex
		<<"&a="<<&a<<endl
		<<"&p1="<<&p1<<endl
		<<"&b="<<&b<<endl
		<<"&p2="<<&p2<<endl
		<<"p2="<<int(p2)<<endl
		<<"&p3="<<&p3<<endl
		<<"p3="<<int(p3)<<endl
		<<"&c="<<&c<<endl
		<<"p1="<<int(p1)<<endl;
	return 0;
}

