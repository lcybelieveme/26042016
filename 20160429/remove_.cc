///
///@date   2016-04-29 23:56:40
///
 
 
 
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<int> vecInt{1,2,3,4,5,6,7,8,9};
	vecInt[2]=vecInt[4]=vecInt[6]=99;
	for(auto &elem:vecInt)
	{
		cout<<elem<<" ";
	}
	cout<<endl;

	std::less<int> lt;
	vecInt.erase(remove_if(vecInt.begin(),vecInt.end(),bind1st(lt,10)),vecInt.end());

	for(auto &elem:vecInt)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
}
