class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
         vector<int> solution;
         vector<vector<int>> result;
         if(k>n||n==0) return result;
         DFS(0, 1, n, k, result, solution);   
         return result;
    }
    
    void DFS(int depth, int index, int n,int k, vector<vector<int>> & result, vector<int>& solution)
    {
        if(depth==k) 
        {
            result.push_back(solution);
            return ;
        }
        for(int i=index;i<=n;++i)
        {
           solution.push_back(i);
           DFS(depth+1, i+1, n, k, result, solution);   
           solution.pop_back();
        }
    }
};
