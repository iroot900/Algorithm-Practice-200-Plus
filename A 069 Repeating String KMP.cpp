#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std; 

vector<int> pref(string str)
{
	int n = str.size();
	vector<int> f(n, 0);
	f[0] = 0; 
	for (int i = 1; i < n; ++i) // n*log(n)
	{
		int last = f[i - 1];
		while (last>0 && str[i] != str[last]) last = f[last - 1];
		if (str[i] == str[last]) f[i] = last + 1;
	}
	return f;
}

int repeatingLen(string str)
{
	int n = str.size(); if (n < 2) return n;
	auto ret = pref(str);
	return str.size() - ret[str.size() - 1];
}

bool isRepeated(string str)
{
	int n = str.size();
	auto prefix = pref(str);
	if (prefix[n-1]<2) 
	{
		cout << "No such substr" << endl<<endl;
		return false;
	}
	int len = n - prefix[n-1];
	if (n % len == 0)
	{
		cout << "\"" << str << "\"" << " is constructed by " << "\"" << str.substr(0, len) << "\"" << " by " << n / len << " times!" << endl << endl;
		return true;
	}
	cout << "No such substr" << endl << endl;
	return false;
}
 
int main()
{
	string str = "abbabbabb";
	auto ret = pref(str);
	for (auto item : ret) cout << item << " ";
	cout << endl;
	cout << repeatingLen(str) << endl;
	cout << endl;

	isRepeated(str);
	isRepeated("abcabcabcd");
	isRepeated("abababab");
}
