#include <iostream>
#include <string>
using namespace std;

void replace(string &text, string& target, string& str)
{
	int p=0;
	while(1)
	{
		p=text.find(target);
		if(p==string::npos) return ;
		text.replace(p,target.size(),str);
		p=p+(int)sizeof(str);
	}
}

int main()
{
	string target="the";
	string str="THE";
	string text="the sun is shining, the water is clean!";
	cout<<text<<endl;

	replace(text,target,str);
	cout<<text<<endl;
	return 0;
}
