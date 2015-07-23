#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int remainIndex(vector<vector<int>>& jobs,int kth)
{
	int i=kth-1;
	for(;i>=0;--i)
	{
		if(jobs[kth][0]>=jobs[i][1]) break;
	}
	return i;
}

int maxProfit(vector<vector<int>>& jobs)
{
	sort(begin(jobs),end(jobs),[](vector<int> left, vector<int> right){ return left[1]<right[1];} );

	int n=jobs.size();
	if(n==0) return 0;
	vector<int> f(n,0);
	f[0]=jobs[0][2];

	for(int i=1;i<n;++i)
	{
		int index=remainIndex(jobs,i);
		f[i]=max(index==-1?0:f[index]+jobs[i][2],f[i-1]);
	}

	return f[n-1];
}

int main()
{
	vector<vector<int>> jobs={{3,10,20},{1,2,50},{6,19,100},{2,100,200}};
	
	cout<<maxProfit(jobs)<<endl;
	return -1;
}
