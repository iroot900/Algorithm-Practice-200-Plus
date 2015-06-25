class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n=nums.size();
        // start and end,
        // when jump happen end-next is bigger than 1 step, and next is the new start
        // compare with start, write into result,  
        int start=0;
        for(int i=0;i<n;++i)
        {
            if(i==n-1||nums[i+1]-nums[i]!=1)//jump happend
            {
                string item;
                if(i==start)
                {
                    item=to_string(nums[i]);
                }
                else
                {
                    item=to_string(nums[start])+"->"+to_string(nums[i]);
                }
                result.push_back(item);
                start=i+1;
            }
        }
        return result;
    }
};
