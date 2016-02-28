 ///
 /// @file    class_member_init.cc
 /// @author  JinXin(xinge1231@qq.com)
 /// @date    2016-02-27 16:14:26
 ///
 
#include <iostream>
using namespace std;

class Point
{
	public:
		Point(int x_pos,int y_pos)
		: _x_pos(x_pos)
		, _y_pos(y_pos)
		, _x_ref(_x_pos)//引用成员初始化
		, _y_ref(_y_pos)
		{
			cout<<"Point init"<<endl;
		}

		~Point()
		{
			cout<<"Point destroy"<<endl;
		}

		
/*		Point(const Point & cp)//复制构造函数
		: _x_pos(cp._x_pos)
		, _y_pos(cp._y_pos)
		, _x_ref(cp._x_pos)
		, _y_ref(cp._y_pos)
		{
			cout<<"Point cp init"<<endl;
		}
*/	
		void SetPoint(int x_pos,int y_pos)
		{
			_x_pos=x_pos;
			_y_pos=y_pos;
		}
		void PrintPoint()
		{
			cout<<"("<<_x_pos<<","<<_y_pos<<") "
				<<"x_ref="<<_x_ref<<",y_ref="<<_y_ref<<endl;
		}
	private:
		int _x_pos;
		int _y_pos;
		int & _x_ref;//引用成员
		int & _y_ref;
};

class Line
{
	public:
		Line(int x1,int y1,int x2,int y2)
		: _point_begin(x1,y1)//对象成员初始化
		, _point_end(x2,y2)
		, kWidth(2)//常量成员初始化
		{
			cout<<"Line Init"<<endl;
			_total_line_num++;
		}

		~Line()
		{
			cout<<"Line destroy"<<endl;
			_total_line_num--;
		}

	//	Line(const Line & cp);
		void Draw()
		{
			cout<<"Begin:";
			_point_begin.PrintPoint();
			cout<<"End:";
			_point_end.PrintPoint();
			cout<<"Width:"<<kWidth<<endl;
		}

		static void Print_total_line_num()//静态成员函数
		{
			cout<<"The total line num is "<<_total_line_num<<endl;
		}

	private:
		Point _point_begin;
		Point _point_end;
		const int kWidth;//常量成员
		static int _total_line_num;//静态成员
};

int Line::_total_line_num=0;//静态成员初始化


int main()
{
	Point p1(1,2);
	Point p2=p1;
	p1.SetPoint(3,4);
	p1.PrintPoint();
	p2.PrintPoint();
	Line l1(0,0,1,1),l2(1,1,2,2);
	l1.Draw();
	Line::Print_total_line_num();//静态成员函数调用
	return 0;
}
