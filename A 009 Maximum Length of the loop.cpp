#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int maxLoop( vector<int> & nextIndex)
{
	int mlen=0;
	int n=nextIndex.size();
	vector<bool> visited(n,false);
	unordered_set<int> previous;
	for(int i=0;i<n;++i)
	{
		int cur=i;
		cout<<i<<" :";
		while(1)
		{
			cout<<cur<<" ";
			if(previous.count(cur)!=0) {mlen=max(mlen,(int)previous.size());previous.clear();}
			if(visited[cur]) {previous.clear(); break;}
			visited[cur]=true;
			previous.insert(cur);
			cur=nextIndex[cur];
		}
		cout<<endl;
	}
	return mlen;
}

int main()
{
	vector<int> nextIndex={3,2,1,4,0,6,7,8,9,10,11,3};

	cout<<maxLoop( nextIndex)<<endl;
}
