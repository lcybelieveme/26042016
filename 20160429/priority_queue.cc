///
///@date   2016-04-29 21:35:53
///
 
 
 
#include <iostream>
#include <queue>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
int test(void)
{
	priority_queue<int> pque;
	int n;
	while(cin>>n)
	{
		pque.push(n);
	}
#if 0
	for(auto &elem:pque)
	{
		cout<<elem<<" ";
	}
	cout<<endl;

	priority_queue<int>::iterator it=pque.begin();
	cout<<*it<<endl;
#endif
	while(!pque.empty())
	{
		cout<<pque.top()<<" ";
		pque.pop();
	}
	cout<<endl;
}


int main()
{
	priority_queue<int,vector<int>,std::greater<int>> pque;
	int n;
	while(cin>>n)
	{
		pque.push(n);
	}


	while(!pque.empty())
	{
		cout<<pque.top()<<" ";
		pque.pop();
	}
	cout<<endl;

	
}
