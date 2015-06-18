class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> data;
        int left=0;
        int n=nums.size();
        if(n<2||k==0) return false;
        data.insert(nums[0]);
        for(int i=1;i<n;++i)
        {
                auto it= data.lower_bound(nums[i]);
                if(it==data.end())
                {
                    if(abs(nums[i]-*(--it))<=t) return true;
                }
                else if(abs(nums[i]-*(it))<=t)
                {
                    return true;
                }
                else if(it!=data.begin()&&abs(nums[i]-*(--it))<=t)
                {
                    return true;
                }
                
                if(data.size()==k)
                {
                    data.erase(nums[left]);
                    ++left;
                }
                data.insert(nums[i]);
        }
        return false;
    }
};
