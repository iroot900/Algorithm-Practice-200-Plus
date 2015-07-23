#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& keys, int left, int right, int pivot)
{
	int index=left;
	for(int i=left;i<right;++i)
	{
		if(keys[i]<pivot) swap(keys[i],keys[index++]);
		else if(keys[i]==pivot) { swap(keys[i], keys[right]); --i;}
		//here the only difference. 
	}
	swap(keys[index],keys[right]);
	return index;//l; should be same. 
}

void lockKey(vector<int>& keys, int left, int right, vector<int> & locks)
{
	if(left>=right) return ;
	int p=partition(keys,left, right, locks[right]);
	partition(locks,left, right, keys[p]);
	lockKey(keys,left,p-1,locks);
	lockKey(keys,p+1,right,locks);
}

void lockKey(vector<int>& keys, vector<int>& locks)
{
	int n=keys.size();  if(n<2) return ;
	lockKey(keys,0,n-1,locks);
}

int main()
{
	vector<int> keys={2,5,3,1,4};
	vector<int> locks={1,5,4,2,3};
	lockKey(keys,locks);
	for(auto key:keys) cout<<key<<" "; cout<<endl;
	for(auto lock:locks) cout<<lock<<" "; cout<<endl;
}
