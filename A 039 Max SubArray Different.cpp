#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int subArrayDiff(vector<int>& nums)
{
	int n=nums.size();
	if(n<2) return -1;
	vector<int> fmax(n),fmin(n),gmax(n),gmin(n);
	vector<int> ffmax(n),ffmin(n),ggmax(n),ggmin(n);

	fmax[0]=nums[0];
	fmin[0]=nums[0];
	ffmax[0]=nums[0];
	ffmin[0]=nums[0];
	for(int i=1;i<n;++i)
	{
		if(fmax[i-1]+nums[i]<nums[i])  fmax[i]=nums[i];
		else fmax[i]=fmax[i-1]+nums[i];
		ffmax[i]=max(ffmax[i-1],fmax[i]);
		
		if(fmin[i-1]+nums[i]>nums[i])   fmin[i]=nums[i];
		else fmin[i]=fmin[i-1]+nums[i];
		ffmin[i]=min(ffmin[i-1],fmin[i]);
	}

	gmax[n-1]=nums[n-1];
	gmin[n-1]=nums[n-1];
	ggmax[0]=nums[n-1];
	ggmin[0]=nums[n-1];
	for(int i=n-2;i>=0;--i)
	{
		if(gmax[i+1]+nums[i]<nums[i])   gmax[i]=nums[i];
		else gmax[i]=gmax[i+1]+nums[i];
		ggmax[i]=max(ggmax[i+1],gmax[i]);

		if(gmin[i+1]+nums[i]>nums[i])   gmin[i]=nums[i];
		else gmin[i]=gmin[i+1]+nums[i];
		ggmin[i]=min(ggmin[i+1],gmin[i]);
	}


	int diff=0;
	for(int i=1;i<n;++i)
	{
		if(abs(ffmin[i-1]-ggmax[i])>=diff)
		{
			diff=abs(ffmin[i-1]-ggmax[i]);
		}
		
		if(abs(ggmin[i]-ffmax[i-1])>=diff)
		{
			diff=abs(ggmin[i]-ffmax[i-1]);
		}
	}
	return diff;
}

int main()
{
	vector<int> data={2,-1,-2,1,-4,2,8};
	cout<<subArrayDiff(data)<<endl;
}
