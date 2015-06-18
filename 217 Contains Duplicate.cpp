class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> data;
        //if(n<=1) return false; 
        for(int i=0;i<n;++i)
        {
            if(data.find(nums[i])==data.end()) data.insert(nums[i]);
            else return true;
        }
        return false;
    }
};
