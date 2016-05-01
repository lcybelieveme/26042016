///
///@date   2016-04-28 19:23:13
///
 
 
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template<typename T,int num>
class que
{
public:
	que()
	:_top(0)
	{
	}
	
	void push(const T&);
	bool pop(T&);
	bool empty();
	bool full();

private:
	int _top;
	T  _que[num];
};

template<typename T,int num>
void que<T,num>::push(const T&t)
{
	if(_top==num) 
	{
		cout<<"que full"<<endl;
		return;
	}
	_que[_top]=t;
	++_top;
}

template<typename T,int num>
bool que<T,num>::pop(T&t)
{
	if(_top==0) 
	{
		cout<<"que empty"<<endl;
		return false;
	}
	t=_que[0];
	for(int i=0;i<_top;++i)
	{
		_que[i]=_que[i+1];
	}
	--_top;
	return true;
}
template<typename T,int num>
bool que<T,num>::empty()
{
	if(_top==0)return true;
	return false;
}

template<typename T,int num>
bool que<T,num>::full()
{
	if(_top==num)return true;
	return false;
}

int main()
{
	que<int,10>myque;
	cout<<"quenue is empty?  "<<myque.empty()<<endl;

	myque.push(5);
	cout<<"quenue is empty?  "<<myque.empty()<<endl;

	for(int i=1;i<10;++i)
	{
		myque.push(i);
	}

	cout<<"quenue is full?  "<<myque.full()<<endl;

	int n;
	for(int i=0;i<10;i++)
	{
		myque.pop(n);
		cout<<n<<" ";
	}
	

	cout<<endl;
}


