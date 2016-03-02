 ///
 /// @file    conditon.cc
 /// @author  JinXin(xinge1231@qq.com)
 /// @date    2016-02-29 21:14:57
 ///
 
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

class Condition
{
	public:
		Condition()//初始化条件变量和互斥锁
		{
			pthread_mutex_init(&_mutex,NULL);
			pthread_cond_init(&_cond,NULL);
			cout<<"Init condition."<<endl;
		}
		~Condition()
		{
			pthread_cond_destroy(&_cond);
			cout<<"Destory conditon."<<endl;
		}
		void Wait()//等待条件
		{
			pthread_cond_wait(&_cond,&_mutex);
		}
		void Signal()//激发条件
		{
			pthread_cond_signal(&_cond);
			cout<<"Wake up!"<<endl;
		}
		void Unlock()//用于手动解锁
		{
			pthread_mutex_unlock(&_mutex);
		}
	private:
		pthread_mutex_t _mutex;
		pthread_cond_t _cond;
};

Condition cond;
void * pthfunc(void *parg)
{
	int id;
	id=(int)parg;//将指针转为整型
	cout<<"Im pth"<<id<<",Im in."<<endl;
	cond.Wait();
	cout<<"Im pth"<<id<<",Im awake."<<endl;
	cond.Unlock();
}

int main()
{
	pthread_t pth1,pth2;
	pthread_create(&pth1,NULL,pthfunc,(void *)1);
	pthread_create(&pth2,NULL,pthfunc,(void *)2);
	sleep(1);//防止后面过快执行
	cond.Signal();
	cond.Signal();
	pthread_join(pth1,NULL);
	pthread_join(pth2,NULL);
	return 0;
}



