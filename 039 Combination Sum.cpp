class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> solution;
        sort(begin(candidates),end(candidates));
        DFS(0, 0, target, candidates, solution, result);
        return result;
    }
    
    void DFS(int sum, int index, int target, vector<int>& candidates, vector<int>& solution,vector<vector<int>>& result)
    {
        // 2 3 6  7   --- 7  
        if(sum==target)
        {
            result.push_back(solution);
            return ;
        }
        for(int i=index;i<candidates.size();++i)
        {
            if(sum+candidates[i]>target)
            return; 
           //if(i>0&&candidates[i]==candidates[i-1]) continue; there line needed if duplicate exist. (though infinite times so, should no duplicate. but if there is, this could solve the problem)
            solution.push_back(candidates[i]);// index is key here, can't be use many times. but increasing order, so can't go back-- avoid duplicate, can go to same level.
            DFS(sum+candidates[i], i,target, candidates, solution, result);
            solution.pop_back();
        }
    }
};
