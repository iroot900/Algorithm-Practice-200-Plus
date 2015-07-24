#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//house painter same thing. 

int validString(int n)
{
	//like
	if(n<=2) return pow(3,n);
	vector<int> same(n);
	vector<int> diff(n);
	same[1]=3;
	diff[1]=6;
	for(int i=2;i<n;++i)
	{
		//last two are same. 
		same[i]=diff[i-1]+same[i-1];
		diff[i]=diff[i-1]+same[i-1]*2;
	}
	return same[n-1]+diff[n-1];
}

int main()
{
	for(int i=3;i<8;++i)
	{
		cout<<validString(i)<<endl;
	}
}
