//Given array find h, such that there are at least h number >=h. return the max h.
#include <iostream>
#include <vector>
using namespace std;

//naive way.   --- well not so naive actually . 
int maxH(vector<int>& nums)
{
	//at least no(h) >=h, basically , the max could be h if there are h number. 
	sort(begin(nums),end(nums), greater<int> ());
	//if the smallest one is greater or equal h then, h it is.
	//if not, only could be h-1. again for h-1. same logic --> gready
	for(int i=nums.size();i>0;--i)
	{
		if(nums[i-1]>=i) return i;
	}
	return 0;
}

//another way
//main logic:
// if kth largest number >=k then, it's k (or k+)
// 987654321 

int partition(vector<int>& nums,int left, int right)
{
	int index=left;
	for(int i=left;i<right;++i)
	{
		if(nums[left]>=nums[right]) { swap(nums[left],nums[index]); ++index; }
	}
	swap(nums[right],nums[index]);
	return index; 
}

int quickH(vector<int>& nums, int left, int right)
{
	if(left==right) 
	{
		if(nums[left]>=left+1) return left+1;//when valid this always true, include the 0 case
		else return 0; //if not valid always end up here. 
	}
	int kth=partition(nums, left, right);
	if(nums[kth]>=kth+1) return quickH(nums,kth,right);//valid are kept
	else return quickH(nums,left,kth-1);
}

int maxh(vector<int>& nums)
{
	return quickH(nums,0,nums.size()-1);
}

int main()
{
	vector<int> data={3,5,4,6,7,8};
	vector<int> data2={3,2,5};
	cout<<maxH(data)<<endl;
	cout<<maxh(data)<<endl;
	cout<<maxH(data2)<<endl;
	cout<<maxh(data2)<<endl;
}
