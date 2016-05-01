///
///@date   2016-04-26 18:56:26
///
 
 
 
#include <iostream>

using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class point;

class Anotherpoint
{
friend point;
friend ostream& operator<<(ostream&,const Anotherpoint&);
public:
	Anotherpoint(int x=0,int y=0)
	:_ix(x)
	,_iy(y)
	{}
	
private:
	int _ix;
	int _iy;
};

ostream&operator<<(ostream&os,const Anotherpoint& A1)
{
	os<<"("<<A1._ix<<","<<A1._iy<<")"<<endl;
	return os;
}


class point
{
friend ostream& operator<<(ostream&,const point&);
public:
	point(int x=1,int y=1)
	:_ix(x)
	,_iy(y)
	{}

	point(const Anotherpoint&p1)
	:_ix(p1._ix)
	,_iy(p1._iy)
	{}

	operator int()
	{
		return _ix;
	}

	operator double()
	{
		return _ix*_iy;
	}
	
	operator Anotherpoint()
	{
		return Anotherpoint(_ix,_iy);
	}

private:
	int _ix;
	int _iy;
};

ostream&operator<<(ostream&os,const point&p1)
{
	os<<"("<<p1._ix<<","<<p1._iy<<")"<<endl;
}

int main()
{
	point pt(3,4);
	cout<<pt<<endl;

	
	cout<<"x="<<(int)pt<<endl;

	double y=pt;
	cout<<"y="<<y<<endl;

	Anotherpoint pt1;
	pt1=pt;
	cout<<"Anotherpoint="<<pt1<<endl;

	point p1;

	int ds=2;
	p1=ds;
	cout<<"point p1="<<p1<<endl;

	return 0;
}
