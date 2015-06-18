class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>  result;
        vector<int> solution;
        DFS(0,1,  k, 0,  n, result, solution);
        return result;
    }
    
    void DFS(int no, int index, int k,int sum, int n, vector<vector<int>> & result, vector<int>& solution)
    {
        if(sum>n) return ;
        if(no==k) {
            if(sum==n)
            result.push_back(solution);
            return ;
        }
        for (int i=index;i<=9;i++)
        {
            solution.push_back(i);
            DFS(no+1, i+1,  k, sum+i,  n, result, solution);
            solution.pop_back();
        }
    }
};
