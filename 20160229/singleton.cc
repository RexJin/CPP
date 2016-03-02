 ///
 /// @file    singleton.cc
 /// @author  JinXin(xinge1231@qq.com)
 /// @date    2016-02-29 15:46:23
 ///
 
#include <iostream>
using namespace std;

class Singleton
{
	public:
		static Singleton * GetInstance()
		{
			if(NULL==_instance)
			{	
				_instance=new Singleton;
				return _instance;
			}
			else
				return _instance;
		}

		static int Destroy()
		{
			delete _instance;//delete会自动调用析构函数.此时在类内部,可以调用私有函数.
			_instance=NULL;
			return 0;
		}

	private:
		Singleton()
		{
			cout<<"Get Singleton instance."<<endl;
		}
		~Singleton()//不能在此处用delete,会造成循环delete,内存错误
		{
			cout<<"Destory Singleton instance."<<endl;
		}
		static Singleton * _instance;
};

Singleton * Singleton::_instance=NULL;

int main()
{
	Singleton * s1=Singleton::GetInstance();
	Singleton * s2=Singleton::GetInstance();
//	Singleton s3;//构造函数私有,无法创建
	cout<<s1<<endl<<s2<<endl;
//	delete s1;//错误.delete调用析构函数.由于析构函数私有,无法在外部调用.
	Singleton::Destroy();
	cout<<s1<<endl<<s2<<endl;
}
