#include <iostream>
#include <vector>
using namespace std;

bool reachable(vector<int> river)
{
	int n=river.size();
	if(n<0) return false;
	vector<vector<bool>> f(n,vector<bool>(n,false));

	//from i to j. 
	//
	f[0][0]=true;
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(river[i]==0||river[j]==0) continue;
			if(i==0&&j==2&&river[j]) f[i][j]=true;
			int step=j-i;// 5 step..
			if(((i-(step-1)>=0)&&f[i-(step-1)][i])||((i-step>=0)&&f[i-step][i]))
			f[i][j]=true;
			cout<<i<<"->"<<j<<": ? "<<f[i][j]<<endl; 
		}
	}
	for(int i=0;i<n;++i){ if(f[i][n-1]) return true;}
}

int main()
{
	vector<int> river={1,1,1,0,1,1,0,0,1};
	for_each(begin(river),end(river),[](int x) {cout<<x;});
	cout<<endl;
	cout<<reachable(river)<<endl;
	
	vector<int> river1={1,1,0,0,1,1,0,0,1};
	for_each(begin(river1),end(river1),[](int x) {cout<<x;});
	cout<<endl;
	cout<<reachable(river1)<<endl;
	
	vector<int> river2={1,1,1,0,1,0,0,0,1};
	for_each(begin(river2),end(river2),[](int x) {cout<<x;});
	cout<<endl;
	cout<<reachable(river2)<<endl;
}
