class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool solved = false;
     	DFS(0, 0, board, solved);
    }
    
    bool valid(int row, int col, char digit, vector<vector<char>>& matrix)
{
	for (int j = 0; j<9; ++j)
	{
		if (matrix[row][j] != '.'&&j != col&&digit == matrix[row][j]) return false;
		if (matrix[j][col] != '.'&&j != row&&digit == matrix[j][col]) return false;
	}

	// 0 1 2 3 --- 0 1 2 3
	int upper = row / 3, left = col / 3;
	for (int i = upper * 3; i<upper * 3 + 3; ++i)
	{
		for (int j = left * 3; j<left * 3 + 3; ++j)
		{
			if (matrix[i][j] != '.'&&i != row&&j != col&&digit == matrix[i][j]) return false;
		}
	}
	return true;
}

void DFS(int row, int col, vector<vector<char>>& matrix, bool& solved)
{
//	cout << row << " " << col << endl;
	if (row == 8 && col == 9) { solved = true; return; }
	row = row + col / 9;
	col = col % 9;
	if (matrix[row][col] != '.')// if setup filled then go to next.   
		DFS(row, col + 1, matrix, solved);
	else
	{   // check if could be filled with any 
		for (char i = '1'; i <= '9'; i++)
		{
			if (valid(row, col, i, matrix))// if valid give it a try
			{
				matrix[row][col] = i;
				DFS(row, col + 1, matrix, solved);
				if (solved) return;// when go up , could be solved already then go up. 
				matrix[row][col] = '.';
			}
		}// if all tried or no valid, then go up. 
	}
	if (row == 0 && col == 0) cout << "unsolvable!" << endl;// if the first return from checked all, that means, filled. remember deep search. 
}

};
