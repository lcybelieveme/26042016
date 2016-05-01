///
///@date   2016-04-26 20:24:54
///
 
 
#include <string.h> 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class String
{
	friend ostream&operator<<(ostream &,const String&);
	class tstrngpro
	{
		public:
			tstrngpro(String&s,int idx)
			:_str(s)
			,_idx(idx)
			{}
			char &operator=(char);
			operator char();
		private:
			String &_str;
			int _idx;
	};

public:
	String();
	String(const char*);
	String(const String&);
	String&operator=(const String&);
	~String();

	tstrngpro operator[](int idx);

	int use_count();
	int size();
private:
	char*_pstr;
};

ostream&operator<<(ostream&os,const String&s1)
{
	os<<s1._pstr;
	return os;
}

char&String::tstrngpro::operator=(char ch)
{
	if(_str.use_count()==1) 
	{
		_str._pstr[_idx]=ch;
		return _str._pstr[_idx];
	}
	else
	{
		char *temp=new char[strlen(_str._pstr)+2];
		strcpy(temp,_str._pstr);
		temp[_str.size()+1]=1;
		--_str._pstr[_str.size()+1];
		_str._pstr=temp;
		_str._pstr[_idx]=ch;
		return _str._pstr[_idx];
	}
}

String::tstrngpro::operator char()
{
	return _str._pstr[_idx];
}

int String::size()
{
	return strlen(_pstr);
}

int String::use_count()
{
	return _pstr[this->size()+1];
}

String::String()
{
	_pstr=new char[2];
	_pstr[1]=1;
}
String::String(const char*s)
{
	_pstr=new char[strlen(s)+2];
	strcpy(_pstr,s);
	_pstr[strlen(s)+1]=1;
}

String::String(const String&s)
{
	_pstr=s._pstr;
	++_pstr[size()+1];
}

String&String::operator=(const String&s)
{
	if(this!=&s)
	{
		if(use_count()==1)
		{
			cout<<"operator="<<endl;
			delete []_pstr;
		}
		else
		{
			--_pstr[size()+1];
		}
		_pstr=s._pstr;
		++_pstr[size()+1];
	}
	return *this;
}

String::~String()
{
	if(use_count()==1)
	{
		cout<<"~String()"<<endl;
		delete _pstr;
	}
	else
	--_pstr[size()+1];
}

String::tstrngpro String::operator[](int idx)
{
	return tstrngpro(*this,idx);
}

int main()
{
#if 0
	String s1="hello world";
	cout<<s1.use_count()<<endl;

	String s2;
	s2=s1;
	cout<<s1.use_count()<<endl;

	return 0;
#endif
	String s0;
	cout<<"s0's use_count="<<s0.use_count()<<endl;
	String s1="Hello";
	String s2="World";
	String s3=s2;
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	cout<<"s3="<<s3<<endl;
	cout<<"s1's use_count="<<s1.use_count()<<endl;
	cout<<"s2's use_count="<<s2.use_count()<<endl;
	cout<<"s3's use_count="<<s3.use_count()<<endl;

	s3=s1;
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	cout<<"s3="<<s3<<endl;
	cout<<"s1's use_count="<<s1.use_count()<<endl;
	cout<<"s2's use_count="<<s2.use_count()<<endl;
	cout<<"s3's use_count="<<s3.use_count()<<endl;

	cout<<endl;
	s3[0]='h';
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	cout<<"s3="<<s3<<endl;
	cout<<"s1's use_count="<<s1.use_count()<<endl;
	cout<<"s2's use_count="<<s2.use_count()<<endl;
	cout<<"s3's use_count="<<s3.use_count()<<endl;

	String s4=s3;
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	cout<<"s3="<<s3<<endl;
	cout<<"s4="<<s4<<endl;
	cout<<"s1's use_count="<<s1.use_count()<<endl;
	cout<<"s2's use_count="<<s2.use_count()<<endl;
	cout<<"s3's use_count="<<s3.use_count()<<endl;
	cout<<"s4's use_count="<<s4.use_count()<<endl;
	cout<<endl;

	cout<<s4[0]<<endl;
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	cout<<"s3="<<s3<<endl;
	cout<<"s4="<<s4<<endl;
	cout<<"s1's use_count="<<s1.use_count()<<endl;
	cout<<"s2's use_count="<<s2.use_count()<<endl;
	cout<<"s3's use_count="<<s3.use_count()<<endl;
	cout<<"s4's use_count="<<s4.use_count()<<endl;

	return 0;
}
