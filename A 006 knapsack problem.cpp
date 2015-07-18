#include <iostream>
#include <vector>
using namespace std;

int knapSack(const vector<int>& v, const vector<int>& w,int weight)
{
	int n=v.size();
	vector<int> f(weight+1,0);
	f[0]=0;
	
	for(int i=1;i<=weight;++i)
	{
		f[i]=f[i-1];
		cout<<i<<" : "<<endl;
		for(int j=0;j<n;++j)
		{
			if(i-w[j]>=0)
			f[i]=max(f[i],f[i-w[j]]+v[j]);
//			cout<<f[i]<<" ";
		}
			cout<<f[i]<<" ";
		cout<<endl;
	}

	return f[weight];
}

int main()
{
	vector<int> v={60,100,120};
	vector<int> w={10,20,30};
	cout<<knapSack(v,w,50)<<endl;
}
