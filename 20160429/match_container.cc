///
///@date   2016-04-29 23:42:51
///
 
 
 
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::stack;
using std::queue;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	stack<int,vector<int> > stack1;
	for(int i=0;i<10;++i)
	{
		stack1.push(i);
	}

	while(!stack1.empty())
	{
		cout<<stack1.top()<<" ";
		stack1.pop();
	}
	cout<<endl;

	queue<int> que;
	for(int i=0;i<10;++i)
	{
		que.push(i);
	}
	while(que.size()!=0)
	{
		cout<<que.front()<<" ";
		que.pop();
	}
	cout<<endl;
}
