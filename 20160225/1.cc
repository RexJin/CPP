 ///
 /// @file    1.cc
 /// @author  JinXin(xinge1231@qq.com)
 /// @date    2016-02-25 22:24:17
 ///
 
#include <iostream>
#include <string>

using namespace std;

namespace A
{
	int add(int a,int b=0,int c=0)//默认参数
	{
		return a+b+c;
	}
	double add(double a,double b,double c)//重载
	{
		return a+b;
	}
	string add(string str1,string str2)//重载,连接字符串
	{
		return str1+str2;
	}
}

namespace B
{
	void swap(int &refa,int &refb)//引用传递
	{
		int temp=refa;
		refa=refb;
		refb=temp;
	}
}

int main()
{
	using namespace A;
//	using std::cin;
//	using std::cout;
//	using std::endl;
	int a=1,b=2,c=3;
//  cin>>a>>b>>c;
	cout<<"a+b="<<add(a,b)<<endl;
	cout<<"a+b+c="<<add(a,b,c)<<endl;
	B::swap(a,b);
	cout<<"a="<<a<<",b="<<b<<endl;

	int cc;
	const int ca=5,cb=6;
	const int *pc=&ca;
	cout<<"ca="<<*pc<<endl;
	pc=&cb;
	cout<<"cb="<<*pc<<endl;
	pc=&cc;
	//(*pc)++;//错误
	
	int *pa=new int;//会初始化为0
	cout<<"pa="<<*pa<<endl;
	delete pa;
	
	string str1="hello ",str2="world!",str3;
	str3=add(str1,str2);
	cout<<str3<<"length="<<str3.size()<<endl;
	cout<<str3.substr(6,6)<<endl;
	return 0;
}
