class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> solution;
        vector<vector<int>> result;
        result.push_back(solution);
        sort(begin(nums),end(nums));
        DFS(0, nums, solution, result); 
        return result;
    }
    
    void DFS(int index, vector<int>& nums, vector<int> & solution, vector<vector<int>> & result)
    {// 1, 12 , 123, 13, 2, 23, 3, 
        for(int i=index;i<nums.size();++i)
        { //1 2 3 
            solution.push_back(nums[i]);
            result.push_back(solution);
            DFS(i+1, nums, solution, result);
            solution.pop_back();
        }
    }
};
