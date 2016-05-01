///
//<F8>u6n
///@date   2016-04-28 22:51:57
///
 
 
 
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;
using std::set;
using std::multiset;
using std::map;
using std::pair;

int main()
{
	vector<int> vecInt={1,2,3,4,5};
	list<int> lisInt{2,3,4,5,6};
	deque<int> deqInt{3,4,5,6,7};
#if 1
	for(auto &elem:vecInt)
	{
		cout<<elem<<" ";
	}
	cout<<endl;

	for(auto &elem:lisInt)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
	
	for(auto &elem:deqInt)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
#endif

	vector<int>::iterator it;
	for(it=vecInt.begin();it!=vecInt.end();++it)
	{
		cout<<*it<<" ";
	}
	cout <<endl;

	vector<int> vecint(3,9);
	vecInt.swap(vecint);
	for(it=vecInt.begin();it!=vecInt.end();++it)
	{
	cout<<*it<<" ";
	}
	cout <<endl;
	
	vector<int>::reverse_iterator it1;
	for(it1=vecint.rbegin();it1!=vecint.rend();++it1)
	{
		cout<<*it1<<" ";
	}
	cout<<endl;


	cout<<"list's front= "<<lisInt.front()<<endl;
	cout<<"list's back= "<<lisInt.back()<<endl;
	cout<<"deque's front= "<<deqInt.front()<<endl;
	cout<<"deque's front= "<<deqInt.back()<<endl;

	lisInt.pop_front();
	cout<<"list's front ="<<lisInt.front()<<endl;


	int arr[5]={9,8,7,6,8};
	set<int>setInt(arr,arr+5);
	set<int>::iterator it2;
	for(auto &elem:setInt)
	{
		cout<<elem<<" ";
	}
	cout<<endl;

	multiset<int> setint(arr,arr+5);
	for(auto &elem:setint)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
	
	multiset<int>::reverse_iterator it3;
	for(it3=setint.rbegin();it3!=setint.rend();++it3)
	{
		cout<<*it3<<" ";
	}
	cout<<endl;
	
	pair<int,int>p[4]={pair<int,int>(1,0),pair<int,int>(1,0),pair<int,int>(2,0),pair<int,int>(3,0)};
	map<int,int>ma(p,p+4);
#if 0
	for(int i=0;i<ma.size();++i)
	{
		cout<<ma[i].first<<"  :"<<ma[i].second<<endl;
	}
#endif
	cout<<ma.size();
	cout<<endl;
	map<int,int>::iterator it4;
	for(it4=ma.begin();it4!=ma.end();++it4)
	{
		cout<<it4->first<<"  :  "<<it4->second<<endl;
	}
	return 0;
}
