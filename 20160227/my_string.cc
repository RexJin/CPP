 ///
 /// @file    my_string.cc
 /// @author  JinXin(xinge1231@qq.com)
 /// @date    2016-02-27 22:25:44
 ///
 
#include <iostream>
#include <cstring>
using namespace std;

class String
{
	public:
		String()
		{
			_pstr=NULL;
		}

		String(const char *pstr)
		{
			_pstr=new char[strlen(pstr)+1];
			strcpy(_pstr,pstr);			
		}

		String(const String &rhs)//复制构造函数
		{
			_pstr=new char[strlen(rhs._pstr)+1];
			strcpy(_pstr,rhs._pstr);
		}

		String & operator = (const String & rhs)//赋值运算符重载
		{
			delete _pstr;
			_pstr=new char[strlen(rhs._pstr)+1];
			strcpy(_pstr,rhs._pstr);
			return *this;
		}

		String & operator + (const String & rhs)//+运算符重载
		{
			int str_len;
			char *ppstr;
			if(_pstr==NULL)
			{
				_pstr=new char[strlen(rhs._pstr)+1];
				strcpy(_pstr,rhs._pstr);
			}
			else
			{
				str_len=strlen(_pstr)+strlen(rhs._pstr);
				ppstr=_pstr;
				_pstr=new char[str_len+1];
				strcpy(_pstr,ppstr);
				strcat(_pstr,rhs._pstr);
				delete ppstr;
			}
			return *this;
		}

		~String()
		{
			delete _pstr;
		}

		void Print()
		{
			if(_pstr==NULL)
			{
				cout<<"NULL"<<endl;;
			}
			else
			{
				cout<<_pstr<<endl;
			}
		}
	private:
		char *_pstr;
};

int main()
{
	String str1;
	String str2="Hello,World";
	String str3="wangdao";
	str1=str2+str3;
	str2=str3;
	String str4=str3;

	str1.Print();
	str2.Print();
	str3.Print();
	str4.Print();
	return 0;
}

