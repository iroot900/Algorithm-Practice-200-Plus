#include <iostream>
#include <vector>
using namespace std;

int  productCut(int n)
{
	// 5
	// 1*4
	// 2*3
	vector<int> f(n+1,0);
	f[1]=1;
	for(int i=2;i<=n;++i)
	{
		for(int j=1;j<=i/2;++j)
		{
			f[i]=max(f[i],max(j,f[j])*max(i-j,f[i-j]));
		}
	}
	return f[n];
}

int main()
{
	for(int i=2;i<10;++i)
		cout<<i<<" : "<<productCut(i)<<endl;
}
