#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//find nonespace as start. 
//if it's first is " then find the first "
//find the first space as end. 

vector<string> tokenize(string& str)
{
	vector<string> ret;

	int start=0;
	int end=0;
	while(1)
	{
		start=str.find_first_not_of(" ",end);
		if(start==string::npos) break;
		if(str[start]=='"') 
		{
			end=str.find_first_of("\"",start+1);
			ret.push_back(str.substr(start,end-start+1));
			end=end+1;
		}
		else 
		{
			end=str.find_first_of(" ",start);
			if(end==string::npos) {	ret.push_back(str.substr(start)) ;break;}
			ret.push_back(str.substr(start,end-start));
		}
	}
	return ret;
}

int main()
{
	string str=" \"this is a list\" for testing \"bind words\" purpose" ;
	auto ret=tokenize(str);
	for(auto str:ret)
		cout<<str<<endl;
	return 0;
}
