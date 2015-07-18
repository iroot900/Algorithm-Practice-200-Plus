#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void merge(vector<int>& num,int left, int mid, int right , unordered_map<int,int> & count)
{
	vector<int> f(right-left+1,0);
	int l=left;
	int r=mid+1;
	int index=0;
	while((l<mid+1)&&(r<=right))
	{
		if(num[l]<num[r])
		{
			count[num[l]]+=(right-r+1);
			f[index++]=num[l++];
		}
		else 
		{
			f[index++]=num[r++];
		}
	}
	while(l<mid+1)  f[index++]=num[l++];
	while(r<=right) f[index++]=num[r++];
	for(int i=left;i<=right;++i)
	{
		num[i]=f[i-left];
	}
}

void mergeCount(vector<int>& num, int left, int right, unordered_map<int,int>& count)
{
	if(left==right) return;
	int mid=(left+right)>>1;
	mergeCount(num,left,mid,count);
	mergeCount(num,mid+1,right,count);
	merge(num,left,mid,right,count);
}

int maxSurpasser(vector<int>& num)
{
	unordered_map<int,int> count;
	for(auto nu:num) count[nu]=0;
	mergeCount(num, 0, num.size()-1, count);
	int mmax=0;
	for(auto pir:count)
	{
		mmax=max(mmax,pir.second);
	}
	return mmax;
}

int main()
{
	vector<int> num={10,3,7,1,23,14,6,9};
	for(auto x:num)
		cout<<x<<" ";cout<<endl;
	cout<<"Surpasser: ";
	cout<<maxSurpasser(num);
	cout<<endl;
	for(auto x:num)
		cout<<x<<" ";cout<<endl;
	return 0;
}
