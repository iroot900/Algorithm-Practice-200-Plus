#include <iostream>
#include <vector>
using namespace std;

vector<int> threeIncreasing(vector<int> nums)
{
	int n=nums.size();
	if(n<2) return {};
	
	vector<int> mmin(n);//record mmin index;
	mmin[0]=0;
	for(int i=1;i<n;++i)
	{
		if(nums[i]<nums[mmin[i-1]]) mmin[i]=i;
		else mmin[i]=mmin[i-1];
		cout<<mmin[i]<<" ";
	}
	cout<<endl;

	vector<int> mmax(n);
	mmax[n-1]=n-1;
	for(int i=n-2;i>=0;--i)
	{
		if(nums[i]>nums[mmax[i+1]]) mmax[i]=i;
		else mmax[i]=mmax[i+1];
		cout<<mmax[i]<<" ";
	}
	cout<<endl;

	for(int i=1;i<n-1;++i)
	{
		if(mmin[i]!=i&&mmax[i]!=i)
			return {nums[mmin[i]],nums[i],nums[mmax[i]]};
	}
}

int main()
{
	vector<int> data={4,7,5,1,3,8,9,6,2};
	auto ret=threeIncreasing(data);
	for(auto digit:ret) cout<<digit<<" ";
	cout<<endl;
}
