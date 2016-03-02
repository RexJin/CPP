 ///
 /// @file    mutex_lock.cc
 /// @author  JinXin(xinge1231@qq.com)
 /// @date    2016-02-29 17:11:36
 ///

#include <pthread.h>
#include <iostream>
#define ADD_NUM 200000000

using namespace std;

class MutexLock
{
	public:
		MutexLock()
		{
			pthread_mutex_init(&mutex,NULL);//初始化为互斥锁
			cout<<"Creat Lock."<<endl;
		}
		~MutexLock()
		{
			pthread_mutex_destroy(&mutex);
			cout<<"Destroy Lock."<<endl;
		}
		void Lock()//加锁
		{
			pthread_mutex_lock(&mutex);
		}
		void Unlock()//解锁
		{
			pthread_mutex_unlock(&mutex);
		}
	private:
		 pthread_mutex_t mutex;
};

MutexLock Lock;//定义互斥锁对象
long add_result=0;
void * pthfunc(void * parg)//线程入口函数
{
	int i;
	for(i=0;i<ADD_NUM;i++)
	{
		Lock.Lock();
		++add_result;
		Lock.Unlock();
	}
}

int main()
{
	pthread_t pth1,pth2;
	pthread_create(&pth1,NULL,pthfunc,NULL);
	pthread_create(&pth2,NULL,pthfunc,NULL);
	pthread_join(pth1,NULL);
	pthread_join(pth2,NULL);
	cout<<add_result<<endl;
	return 0;
}

