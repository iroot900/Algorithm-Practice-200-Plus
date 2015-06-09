class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> data;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            data[nums[i]]=i+1;
        }
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            auto it=data.find(target-nums[i]);
            if(it!=data.end())
            {
                if(i+1==it->second) continue;// must be two numbers in different position
                result.push_back(i+1);
                result.push_back(it->second);
                return result;
            }
        }
    }
};
