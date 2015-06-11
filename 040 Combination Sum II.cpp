class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        vector<vector<int> > result;
        vector<int> solution;
        DFS(0,0, target, candidates, result, solution);
        return result;
    }
    
    void DFS(int sum,int index,int target, vector<int>& candidates, vector<vector<int> >& result,vector<int>& solution)
    {
        if(sum==target)
        {
            result.push_back(solution);
            return;
        }
        
        for(int i=index;i<candidates.size();++i)
        {
            if(sum+candidates[i]>target) return;
            if(i>index&&candidates[i]==candidates[i-1]) continue;
            solution.push_back(candidates[i]);
            DFS(sum+candidates[i],i+1, target, candidates, result, solution);
            solution.pop_back();
        }
    }
};
