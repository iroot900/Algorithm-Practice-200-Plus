class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        DFS(0,0, n, result,"");
        return result;
    }
    
    void DFS(int left,int right,int n,vector<string>& result, string solution)
    {
        if(right==n) 
        {
            result.push_back(solution);
            return;
        }
        if(left<n)
        {
            DFS(left+1,right, n, result, solution+"(");
        }
        if(right<left) 
        {
            DFS(left,right+1, n, result, solution+")");
        }
    }
};
