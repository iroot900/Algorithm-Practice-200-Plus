class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
    {
    	int n=nums.size(); if(n<3) return 0;
    	sort(begin(nums),end(nums));
    	
    	int count=0;
    	for(int i=0;i<n;++i)
    	{
    		int left=i+1, right=n-1;
    		while(left<right)
    		{
    			if(nums[left]+nums[right]+nums[i]<target)
    			{
    				count+=right-left;
    				++left;
    			}
    			else  --right;
    		}
    	}
    	return count;
    }
}
