class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        if(n<3) return {};
        vector<vector<int>> result;
        vector<int> solu;
        DFS(n, n, 2, result, solu);
        return result;
    }
    
    void DFS(int n, int remain, int index, vector<vector<int>>& result, vector<int>& solu)
    {
        if(remain==1) {result.push_back(solu);}
        for(int i=index;i<=min(n-1,remain);++i)
        {
            if(remain%i==0)
            {
                solu.push_back(i);
                DFS(n,remain/i, i, result, solu);
                solu.pop_back();
            }
        }
    }
};
