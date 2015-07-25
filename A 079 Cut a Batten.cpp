#include <iostream>
#include <vector>
using namespace std;

int cutBatten(vector<int>& num)
{
	int n=num.size();
	if(n<3) return 0;
	vector<vector<int>> f(n,vector<int>(n,INT_MAX));
	vector<vector<int>> len(n,vector<int>(n,0));

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i>=j) len[i][j]=0;
			else 
			len[i][j]=len[i][j-1]+num[j]-num[j-1];
		}
		cout<<len[i][n-1]<<endl;
	}

	for(int lenth=1;lenth<n;++lenth)
	{
		for(int i=0;i<n-lenth;++i)
		{
			if(lenth==1) f[i][i+lenth]=0; 
			for(int k=i+1;k<i+lenth;++k)
			{
				f[i][i+lenth]= min((f[i][i+lenth]),f[i][k]+f[k][i+lenth]+len[i][i+lenth]);
			}
		}
	}
	return f[0][n-1];
}

int main()
{
	vector<int> data={0,3,5,7,13};
	cout<<endl;
	cout<<cutBatten(data)<<endl;
	
	vector<int> data2={0,3,5,9};
	cout<<endl;
	cout<<cutBatten(data2)<<endl;
	return 0;
}
