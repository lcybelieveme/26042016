///
///@date   2016-04-29 22:33:52
///
 
 
 
#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;

void add(pair<const string,int> &p)
{
	p.second+=2;	
}

int main(void)
{
	map<string,int> mpInt{
			{"hello",1},
			{"world",1},
			{"how",1},
			{"are",1},
			{"you",1}
	};

	for_each(mpInt.begin(),mpInt.end(),add);

	for(map<string,int>::iterator it=mpInt.begin();it!=mpInt.end();++it)
	{
		cout<<it->second<<"                     "<<it->first<<endl;
	}

	return 0;
}
