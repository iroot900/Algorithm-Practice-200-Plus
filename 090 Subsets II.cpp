class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> solution;
        vector<vector<int>> result;
        sort(begin(nums),end(nums));
        result.push_back(solution);
        DFS(0,  nums, result,  solution);
        return result;
    }
    
     void DFS(int index, vector<int>& nums, vector<vector<int>>& result, vector<int>& solution)
    {    
         for(int i=index;i<nums.size();++i)
         {
             solution.push_back(nums[i]);
             result.push_back(solution);
             DFS(i+1,  nums, result,  solution);
             solution.pop_back();
             while(i<nums.size()-1&&nums[i]==nums[i+1]) ++i;
         }
     }
};
