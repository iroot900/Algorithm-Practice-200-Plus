// given a rod with fixed len. and unit price by different unit
// cut it into different unit which produce maximum total price. 
#include <iostream>
#include <vector>
using namespace std;

int maxCut(const vector<int>& prices)
{
	int n=prices.size();
	vector<int> f(n+1,0);
	f[0]=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
		{
			f[i]=max(f[i],f[i-j]+prices[j-1]);
		}
	}
	return f[n];
}


int main()
{
	vector<int> prices={1,5,8,9,10,17,17,20};
	cout<<maxCut(prices);
	cout<<endl;
	return 0;
}
