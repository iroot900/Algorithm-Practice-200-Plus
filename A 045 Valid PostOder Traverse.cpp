#include <iostream>
#include <vector>
using namespace std;

// last one is the root .and left and right should be two part
// left small, right big. n*log(n);
// how to check left < right
//  if(right>)  right-- 
// if(left<) left++. they shoudl meet . Aha!!!!!
bool validPostTravel(vector<int>& nums,int left, int right)
{
	if(right<=left) return true;
	int l=left, r=right-1;
	while(nums[r]>nums[right]) --r;
	while(nums[l]<nums[right]) ++l;
	return l>r&&validPostTravel(nums,left,r)&&validPostTravel(nums,l,right-1);
}
bool validPost(vector<int>& data)
{
	if(data.size()==0) return true;
	return validPostTravel(data, 0, data.size()-1);
}

int main()
{
	vector<int> data={5,7,6,9,11,10,8};
	cout<<validPost(data)<<endl;
	
	vector<int> data1={7,4,6,5};
	cout<<validPost(data1)<<endl;
}
