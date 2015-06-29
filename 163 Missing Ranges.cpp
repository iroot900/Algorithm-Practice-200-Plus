class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<string> result;
        string solu;
        if(n==0) 
        {
            solu+=to_string(lower);
            if(lower<upper) {solu+="->"; solu+=to_string(upper);}
            result.push_back(solu);
            return result;
        }
        
        int left=lower, right;
        for(int i=0;i<n;++i)
        {
            if(nums[i]<lower) continue;
            if(nums[i]==lower)
            {
                ++left;++lower;
            }
            else if(nums[i]>lower)
            {
                if(nums[i]>upper)
                {
                    right=upper;
                    solu+=to_string(left);
                    if(left<right) {solu+="->"; solu+=to_string(right);}
                    result.push_back(solu);
                    return result;
                }
                    right=nums[i]-1;
                    solu+=to_string(left);
                    if(left<right) {solu+="->"; solu+=to_string(right);}
                    result.push_back(solu);
                    solu.clear();
                left=nums[i]+1;
                lower=nums[i]+1;
            }
        }
        
        if(upper>nums.back())
        {
                right=upper;
                solu+=to_string(left);
                if(left<right) {solu+="->"; solu+=to_string(right);}
                result.push_back(solu);
        }
        return result;
    }
};
