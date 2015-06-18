class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int sum=0;
        int len=INT_MAX;
        for(int i=0;i<n;++i)
        {
            sum+=nums[i];
            if(sum>=s)
            {
                while(sum-nums[start]>=s)
                {
                    sum-=nums[start];
                    ++start;
                }
                len=min(len,i-start+1);
            }
        }
        if(len==INT_MAX) return 0;
        else return len;
    }
};
