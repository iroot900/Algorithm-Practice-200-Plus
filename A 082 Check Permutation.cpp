#include <iostream>
#include <vector>
using namespace std;

bool checkPerm(string str1,string str2)
{
	int n=str1.size(); int m=str2.size();
	if(m!=n) return false;
	vector<int> dict(256,0);
	for(int i=0;i<n;++i)
	{
		dict[str1[i]]++;
	}
	for(int i=0;i<n;++i)
	{
		dict[str2[i]]--;
		if(dict[str2[i]]<0) return false;
	}
	return true;
}

int main()
{
	string str1="thisisastring";
	string str2="astringthisis";
	cout<<checkPerm(str1,str2)<<endl;
	
	str1="thisisastting";
	str2="astringthisis";
	cout<<checkPerm(str1,str2)<<endl;
}
