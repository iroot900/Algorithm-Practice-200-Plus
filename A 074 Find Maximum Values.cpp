#include <iostream>
#include <vector>
using namespace std;

int nonAjacentSum(vector<int> & nums)
{
	int n=nums.size();
	if(n==0) return 0;
	vector<int> f(n+1);
	f[0]=nums[0];
	if(n==1) return f[0];
	f[1]=max(nums[0],nums[1]);
	
	for(int i=2;i<n;++i)
	{
		f[i]=max(f[i-1],f[i-2]+nums[i]);
	}
	return f[n-1];
}

int main()
{
	vector<int> nums={1,5,4,3,2};
	cout<<nonAjacentSum(nums)<<endl;
	
	vector<int> nums2={3,2,5,10,7};
	cout<<nonAjacentSum(nums2)<<endl;
	
	vector<int> nums1={3,2,7,10};
	cout<<nonAjacentSum(nums1)<<endl;
	return 0;
}
