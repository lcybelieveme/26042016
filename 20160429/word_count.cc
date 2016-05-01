///
///@date   2016-04-29 22:53:54
///
 
 
 
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using std::ifstream;
using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::pair;

int main(int argc,char**argv)
{
	ifstream ifs(*(argv+1));
	if(!ifs.good()) {
		cout<<"open ifstream error"<<endl;
		return -1;
	}

	string s1;
	map<string,int> wordmap;
#if 0
	while(ifs>>s1)
	{
		++wordmap[s1];
	}
#endif	
	pair<map<string,int>::iterator,bool> ret;
	while(ifs>>s1)
	{
		ret=wordmap.insert(pair<string,int>(s1,1));
		if(!ret.second)
		{
		//	++wordmap[s1];
			++ret.first->second;
		}
	}

	
//	map<int,string> sortmap;
	for(map<string,int>::iterator it=wordmap.begin();it!=wordmap.end();++it)
	{
		cout<<it->second<<"                         "<<it->first<<endl;
		//sortmap.insert(pair<int,string>(it->second,it->first));
	}
#if 0	
	for(map<int,string>::iterator it=sortmap.begin();it!=sortmap.end();++it)
	{
		cout<<it->second<<"                         "<<it->first<<endl;
	}
#endif



	return 0;
}
