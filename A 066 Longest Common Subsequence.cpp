#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
 
int longestCommomSub(string &A, string &B)
{
	int m = A.size();
	int n = B.size();
	if (m == 0 || n == 0) return 0;
	vector<vector<int>> f(m+1, vector<int>(n+1, 0));
	//for (int i = 0; i < m; ++i) f[i][0] = 0;
	//for (int i = 0; i < n; ++i) f[0][i] = 0;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == 0 || j == 0) f[i][j] = 0;
			else if (A[i - 1] == B[j - 1]) f[i][j] = f[i - 1][j - 1] + 1; // since it only goes up
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			// at i-1 and j-1/  could go one more step
		}
	}
	return f[m][n];
}

int main()
{
	string str1 = "0.aebtcgde";
	string str2 = "taxb.cde/f";
	cout << str1 << endl;
	cout << str2 << endl;
	cout << longestCommomSub(str1, str2) << endl;
}  
