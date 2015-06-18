class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> data;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            auto it=data.find(nums[i]);
            if(it==data.end()) data[nums[i]]=i;
            else
            {
                if(i-data[nums[i]]<=k) return true;
                else
                data[nums[i]]=i;
            }
        }
        return false;
    }
};
