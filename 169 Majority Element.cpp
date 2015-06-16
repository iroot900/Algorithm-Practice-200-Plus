class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
        pair<int,int> major={nums[0],1};
        for(int i=1;i<nums.size();++i)
        {
            if(major.second==0)
            {
                major.first=nums[i];major.second++;
            }
            else if(nums[i]==major.first)
            {
                major.second++;
            }
            else
            major.second--;
        }
        return major.first;
    }
};
