 ///
 /// @file    class_and_object.cc
 /// @author  JinXin(xinge1231@qq.com)
 /// @date    2016-02-26 20:28:47
 ///
#include <cstring> 
#include <iostream>
using namespace std;

class Computer
{
	private:
		char _brand[20];
		float _price;
		char* _infor;
	public:
		Computer()
		:_price(0)
		{
			_infor=new char[10];
			strcpy(_brand,"NoName");
			cout<<"Im here"<<endl;
	//		price_=0;
		}
		Computer(char* brand,float price=0)
		{
			_infor=new char[10];
			set_brand(brand);
			set_price(price);
		}
		Computer(const Computer & com)
		{
			_infor=new char[10];
			strcpy(_infor,com._infor);
			strcpy(_brand,com._brand);
			_price=com._price;
		}
		~Computer()
		{
			delete _infor;
			cout<<"delete"<<endl;
		}
		Computer & operator +(const Computer & com);
		void Print();
		void set_brand(char* brand)
		{
			strcpy(_brand,brand);
		}
	
		void set_price(float price)
		{
			_price=price;
		}
};
Computer & Computer:: operator + (const Computer & com)
{
	strcat(_infor,com._infor);
	strcat(_brand,com._brand);
	_price=com._price+_price;
	return *this;
}
void Computer::Print()
{
	cout<<"brand:"<<_brand<<endl
		<<"price:"<<_price<<endl;
}

int main()
{
	Computer com2("IBM",7000);
	Computer com1;
//	com2.set_brand("Dell");
//	com2.set_price(4000);
	com1+com2;
	com1.Print();
//	com2.Print();
	return 0;
}



