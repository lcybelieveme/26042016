///
///@date   2016-04-29 19:33:13
///
 
 
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void heap_insert(int *arr,int n)              //插入堆尾 再调整堆
{
	int i=(n-1)/2;
	int temp=arr[n];
	while(i>=0&&n!=0)
	{
		//cout<<" I here";
		if(arr[n]>arr[i]) break;

		arr[n]=arr[i];
		arr[i]=temp;
		n=i;
		i=(n-1)/2;
		//cout<<"n="<<n<<"   "<<"i="<<i<<endl;
	}
}

void heap_delete(int *arr,int i,int n)    //删除堆首  将堆尾拿到堆首 再调整堆
{
	arr[i]=arr[n-1];
	int j=i*2+1;
	int temp=arr[i];
	while(j<n-1)
	{
		//cout<<" I here"<<endl;
		if(arr[j]>arr[j+1]) ++j;
		if(arr[i]<arr[j]) break;
		arr[i]=arr[j];
		arr[j]=temp;
		i=j;
		j=i*2+1;
	}
}

void heap_init(int*arr,int n)   //初始化一个数组为一个小根堆
{
	int i=(n-2)/2;
	int j;
	
	for(;i>=0;--i)
	{
		j=2*i+1;
		if(j+1<n)
		{
			if(arr[j]>arr[j+1])
				++j;
		}
		if(arr[i]>arr[j])
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
}

int main()
{
	int arr[10]={4,6,3,7,1,9,10,11,8,14};
#if 0
	for(int i=9;i>=0;--i)
	{
		heap_insert(arr,i);	
	}
#endif
#if 1
	heap_init(arr,10);    //堆初始化

	for(int i=0;i<10;++i)
		cout<<arr[i]<<" ";

	
	cout<<endl;

	for(int i=0;i<10;++i)
	{
		cout<<arr[0]<<" ";
		heap_delete(arr,0,10-i);       //输出堆首 再删除堆首
	}
	cout<< endl;
#endif

	return 0;
}
