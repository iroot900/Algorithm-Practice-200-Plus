class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> data;
        for(auto digit:nums)
            data[digit]=false;
        
        int n=nums.size();
        
        int len=0;
        int maxlen=0;
        for(int i=0;i<n;++i)
        {
            len=0;
            if(data[nums[i]]==false)
            {
                data[nums[i]]=true;++len;
                int cur=nums[i];
                while (data.find(cur+1)!=data.end())
                {
                    data[cur+1]=true;
                    ++cur; ++len; 
                }
                cur=nums[i];
                while (data.find(cur-1)!=data.end())
                {
                    data[cur-1]=true;
                    --cur; ++len; 
                }
                maxlen=max(maxlen,len);
            }
        }
        return maxlen;
    }
};
