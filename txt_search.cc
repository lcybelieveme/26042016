///
///@date   2016-04-30 22:36:19
///
 
 
 
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <sstream>

using std::istringstream;
using std::set;
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::pair;

int main(int argc,char **argv)
{
	ifstream ifs(*(argv+1),std::ios::in);
	map<int,string> line_word;
	string strline;
	int i=1;
	while(getline(ifs,strline))
	{
		line_word.insert(pair<int,string>(i,strline));
		i++;
	}
#if 0
	for(auto &elem:line_word)
	{
		cout<<elem.first<<"            "<<elem.second<<endl;
	}
#endif

	map<string,set<int> > word_count;
	string str;
	for(auto &elem:line_word)
	{
		istringstream ist(elem.second);
		while(ist>>str)
		{
			word_count[str].insert(elem.first);
		}
	}
#if 0
	for(map<string,set<int> >::iterator it=word_count.begin();it!=word_count.end();++it)
	{
		cout<<it->first;
		for(auto &elem:it->second)
		{
			cout<<elem<<" ";
		}
		cout<<endl;
	}
#endif

	string sword;
	cout<<"please input the word you want to search:"<<endl;
	while(cin>>sword)
	{
		cout<<"========================================"<<endl;
		if(word_count.find(sword)==word_count.end()) 
		{
			cout<<"No word"<<endl;
			continue;
		}
		cout<<sword<<" occurs "<<word_count[sword].size()<<" times."<<endl;

		for(auto &elem:word_count[sword])
		{
			cout<<"(line "<<elem<<")  "<<line_word[elem]<<endl;
		}
	cout<<"please input the word you want to search:"<<endl;
	}

}
