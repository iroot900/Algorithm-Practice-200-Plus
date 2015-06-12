class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<bool> row(n, true);//i
    	vector<bool> col(n, true);//j
    	vector<bool> diagL(2*n-1,true);// i+j
    	vector<bool> diagR(2*n-1,true);// n+j-i-1; 
    
    	vector<string> solution(n,string(n,'.'));
    	vector<vector<string>> result;
    	DFS(0, row, col, diagL, diagR, result, solution);
    	return result;
    }
    
    
    bool valid(int i, int j, vector<bool>& row, vector<bool>& col, vector<bool>& diagL, vector<bool>& diagR)// put it here, then must.. no row's OK, col's Ok, diagnal's Ok. 
{
	return row[i] && col[j] && diagL[i + j] && diagR[col.size() + j - i - 1];
}


void DFS(int i, vector<bool>& row, vector<bool>& col, vector<bool>& diagL, vector<bool>& diagR, vector<vector<string>> & result, vector<string>& solution)
{
	int n = row.size();
	if (i == n) { result.push_back(solution); return; }

	for (int j = 0; j < n; ++j)
	{
		if (valid(i, j, row, col, diagL, diagR))
		{
			row[i] = false; col[j] = false; diagL[i + j] = false; diagR[col.size() + j - i - 1] = false;
			solution[i][j] = 'Q';
			DFS(i + 1, row, col, diagL, diagR, result, solution);
			row[i] = true; col[j] = true; diagL[i + j] = true; diagR[col.size() + j - i - 1] = true;
			solution[i][j] = '.';
		}
	}
}

};
