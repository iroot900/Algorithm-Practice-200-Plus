#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// assume '#' is reserved 
string encode(vector<string>& strs)
{
	string ret;
	for(auto str:strs)
	{
		ret=ret+'#'+to_string(int(str.size()))+'#'+str;
	}
	return ret;
}

//main logic:
vector<string> decode(string& str)
{
	vector<string> ret;
	int start=0;
	while(1)
	{
		int suffix=str.find_first_of("#",start+1);
		int end=str.find_first_of("#",suffix+1);
		if(end==string::npos) {ret.push_back(str.substr(suffix+1)) ; break;}
		ret.push_back(str.substr(suffix+1,end-suffix-1));
		start=end;
	}
	return ret;
}

int main()
{
	vector<string> strs={"Load","The","Data","Do Processing!", "A...","mess ", "32432fsa",".fsdk"};	
	for(auto str:strs)
		cout<<str<<" ";
	cout<<endl;
	
	auto ret=encode(strs);
	cout<<ret<<endl;

	auto strings=decode(ret);
	for(auto str:strings)
		cout<<str<<" ";
	cout<<endl;
	
}
