///
///@date   2016-04-26 17:01:45
///
 
 
#include "line.hh"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


class line::_Impl
{
private:
	class point
	{
	private:
		int _ix;
		int _iy;
	public:
		void print()
		{
			cout<<"("<<_ix<<","<<_iy<<")";
		}
		point(int x,int y)
		:_ix(x)
		,_iy(y)
		{}
	};
	point p1,p2;
public:
	void printpoint()
	{
		p1.print();
		cout<<"--->";
		p2.print();
	}
	_Impl(int x,int y,int x1,int y1)
	:p1(x,y)
	,p2(x1,y1)
	{}
};

line::line(int x,int y,int x1,int y1)
{
	_pImpl=new line::_Impl(x,y,x1,y1);
}

line::~line()
{
	delete _pImpl;
}

void line::printline()
{
	_pImpl->printpoint();
}

int main()
{
	line l1(1,2,3,4);
	
	l1.printline();

}

