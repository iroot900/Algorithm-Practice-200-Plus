class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        unordered_map<int,int> remains;
        for(auto x:nums) remains[x]++;
        
        vector<int> solution;
        vector<vector<int>> result;
         DFS(0, nums,result, solution, remains);
        return result;
    }
    
    void DFS(int depth, vector<int>& nums,vector<vector<int>> &result,vector<int>& solution,unordered_map<int,int>& remains)
    {
        if(depth==nums.size())
        {
            result.push_back(solution);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(remains[nums[i]]>0)
            {
                remains[nums[i]]--;
                solution.push_back(nums[i]);
                DFS(depth+1, nums,result, solution, remains);
                solution.pop_back();
                remains[nums[i]]++;
            }
        }
    }
};
