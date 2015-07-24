#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <random>
#include <iomanip>
#include <time.h>
using namespace std;

void median(vector<int>& nums)
{
	int n=nums.size();
	priority_queue<int, vector<int> , greater<int>> minHeap;
	priority_queue<int, vector<int> , less<int>> maxHeap;
	int median=0;
	//compare size first
	//compare with median also...
	for(int i=0;i<n;++i)
	{
		if(maxHeap.size()<minHeap.size())
		{
			if(nums[i]<=median)
			{
				maxHeap.push(nums[i]);
				median=(maxHeap.top()+minHeap.top())>>1;
				cout<<setw(3)<<median<<" ";
			}
			else 
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(nums[i]);
				median=(maxHeap.top()+minHeap.top())>>1;
				cout<<setw(3)<<median<<" ";
			}
		}
		else if(maxHeap.size()>minHeap.size())
		{
			if(nums[i]>=median)
			{
				minHeap.push(nums[i]);
				median=(maxHeap.top()+minHeap.top())>>1;
				cout<<setw(3)<<median<<" ";
			}
			else 
			{
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(nums[i]);
				median=(maxHeap.top()+minHeap.top())>>1;
				cout<<setw(3)<<median<<" ";
			}
		}
		else 
		{
			if(nums[i]<median)
			{
				maxHeap.push(nums[i]);
				median=maxHeap.top();
				cout<<setw(3)<<median<<" ";
			}
			else 
			{
				minHeap.push(nums[i]);
				median=minHeap.top();
				cout<<setw(3)<<median<<" ";
			}
		}
	}//must compare with the top.
}

int main()
{
	srand(time(0));
	vector<int> nums(20);
	for(int i=0;i<20;++i)
	{
		nums[i]=rand()%50;
		cout<<setw(3)<<nums[i]<<" ";
	}
	cout<<endl;
	median(nums);
	cout<<endl;
}
