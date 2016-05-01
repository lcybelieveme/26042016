///
///@date   2016-04-28 20:20:28
///
 
 
#include <stdio.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template<typename T>
class sigleton
{
#if 0
	class deletesingleton
	{
		public:
			deletesingleton()
			{
				cout<<"deletesingleton"<<endl;
			}
		~deletesingleton()
		{
			cout<<"~deletesingleton"<<endl;
			if(_pInstance)
			delete _pInstance;
		}
	};
#endif
public:
	static T*getInstance()
	{
		if(_pInstance==NULL)
			_pInstance=new T;
		return _pInstance;
	}
#if 1
	static void destroy(){
		if(_pInstance!=NULL)
		{
			cout<<"destroy()"<<endl;
			delete _pInstance;
			_pInstance=NULL;
		}
	}
#endif
private:
	sigleton(){}
	~sigleton(){cout<<"~sigleton()"<<endl;}

	static T*_pInstance;
//	static deletesingleton del;
};

//template<typename T>
//typename sigleton<T>::deletesingleton sigleton<T>::del;
template<typename T>
T*sigleton<T>::_pInstance=NULL;

#if 0
template<typename T>
T*sigleton<T>::getInstance()
{
//	static::sigleton<T>::deletesingleton del;
	if(_pInstance==NULL)
		_pInstance=new T;
	return _pInstance;
}
#endif

#if 1
class point
{
public:
	point(int x=0,int y=0)
	:_ix(x)
	,_iy(y)
	{}
private:
	int _ix;
	int _iy;
};
#endif

int main()
{
	int *p=sigleton<int>::getInstance();
	int *q=sigleton<int>::getInstance();

	sigleton<int>::destroy();
	printf("p=%p\nq=%p\n",p,q);

	return 0;
}
