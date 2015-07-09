class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int previous=lower-1; 
        vector<string> result;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==previous+1) {previous=nums[i];}
            else 
            {
                if(previous+2==nums[i])  { result.push_back(to_string(previous+1)); }
                else  { result.push_back( to_string(previous+1)+"->"+to_string(nums[i]-1) );}
                previous=nums[i];
            }
        }
        if(previous+1==upper)  { result.push_back(to_string(previous+1)); }
        else if (previous+1<upper) { result.push_back( to_string(previous+1)+"->"+to_string(upper) );}
        
        return result;
    }
};
