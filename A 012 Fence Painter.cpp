#include <iostream>
#include <vector>
using namespace std;

//actually very similar to jump game. f[i]=f[i-1]+f[i-2]
int painter(int n,int k)
{
	if(n<1) return 0;
	if(n==1) return k;
	vector<int> f(n+1,0);
	f[1]=k;
	f[2]=k*k;
	for(int i=3;i<=n;++i)
	{
		//end with same color or diff color. 
		//nothing to do with previous.
		//this is exactly like jump stairs
		f[i]=f[i-1]*(k-1)+f[i-2]*(k-1);
	}
	return f[n];
}

int main()
{
	int n=5, k=2;
	cout<<painter(n,k)<<endl;
}
