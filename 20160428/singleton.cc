///
///@date   2016-04-26 19:36:22
///
 
 
#include <stdio.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class singleton
{
public:
	static singleton*getInstance();
//private:
	class autorealese
	{
		public:
		~autorealese()
		{
			cout<<"~autorealese"<<endl;
			if(pInstance!=NULL)
				delete pInstance;
		}
	};
private:
	singleton(){}
	~singleton(){cout<<"~singleton"<<endl;}
	static singleton* pInstance;
	static autorealese ato;
};
singleton*singleton::getInstance()
	{
		if(pInstance==NULL)
			pInstance=new singleton;
		return pInstance;
	}

singleton*singleton::pInstance=NULL;
singleton::autorealese ato;

int main()
{
	singleton* p1=singleton::getInstance();
	singleton* p2=singleton::getInstance();

	printf("p1=%p\n",p1);
	printf("p2=%p\n",p2);
}
