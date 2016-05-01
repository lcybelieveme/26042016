#ifndef __MY_LINE_HH__
#define __MY_LINE_HH__

class line
{
public:
	line(int x1,int y1,int x2,int y2);
	~line();
	void printline();
private:
	class _Impl;
	_Impl* _pImpl;
};


#endif
