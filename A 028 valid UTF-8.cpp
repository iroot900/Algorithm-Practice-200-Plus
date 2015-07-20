#include <iostream>
#include <vector>
using namespace std;

template<typename T>
bool valid(const T& bytes)
{
	int n=bytes.size();
	if(n<8||n%8!=0||n>32) return false;
	if(n==8) return (bytes[0]=='0'||bytes[0]==0);
	int len=n/8;
	for(int i=0;i<len;++i)
	{
		if (!(bytes[0]=='1'||bytes[0]==1)) return false;
	}
	if(!(bytes[len]=='0'||bytes[len]==0)) return false;
	for(int i=0;i<len-1;++i)
	{
		if(!(bytes[8*(i+1)]=='1'||bytes[8*(i+1)]==1)) return false;
		if(!(bytes[8*(i+1)+1]=='0'||bytes[8*(i+1)+1]==0)) return false;
	}
	return true;
}

int main()
{
	string str="00101010";
	cout<<valid(str)<<endl;
	vector<int> strs={1,1,0,1,0,1,1,0,1,0,1,1,0,1,1,1};
	cout<<valid(strs)<<endl;
	 str="10101010";
	cout<<valid(str)<<endl;
	 strs={1,1,0,1,0,1,1,0,0,0,1,1,0,1,1,1};
	cout<<valid(strs)<<endl;
}
