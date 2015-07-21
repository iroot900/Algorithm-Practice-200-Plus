#include <iostream>
#include <climits>
#include <vector>
using namespace std;

//sorted unique number array
//gready way,very similar to two sum
//assum target greater than zero. (negative just change position);
vector<int> twoDiff(vector<int>& nums, int target)
{
	int n=nums.size();
	if(n<2) return {INT_MIN,INT_MAX};
	int pl=0, pr=0;
	while(pr<n)
	{
		if(nums[pr]-nums[pl]==target) return {nums[pl],nums[pr]};
		if(nums[pr]-nums[pl]>target) ++pl;
		if(nums[pr]-nums[pl]<target) ++pr;
	}
	return {INT_MIN,INT_MAX};
}

int main()
{
	vector<int> nums={1,2,3,4,5,8,10};
	auto ret=twoDiff(nums,5);
	cout<<ret[0]<<" "<<ret[1]<<endl;
	
	vector<int> nums2={1,2,3,4,5,20,30};
	auto ret2=twoDiff(nums2,5);
	cout<<ret2[0]<<" "<<ret2[1]<<endl;
}
