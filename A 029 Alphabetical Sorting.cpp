//Alphabetical Sorting
// Given a list of words sort it according to the alphabetical order in a given string. 
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
 
vector<string> alphabetical( vector<string>& words, const string &str)
{ 
	unordered_map<char, int> order;
	int index = 0; //not necessary
	for (int i = 0; i < str.size(); ++i)
	{
		if (order.count(str[i]) == 0) order[str[i]] = index++;
	}

	sort(begin(words), end(words), [&order](string left, string right){
		int l = 0, r = 0;
		while (l < (int)left.size() && r < (int)right.size())
		{
			if (order[left[l]]>order[right[r]]) return false;
			else if (order[left[l]] < order[right[r]]) return true;
			++l; ++r;
		}
		if (l <(int) left.size()) return true;
		else return false;
	});

	return words;
}

int main()
{
	vector<string> words = { "face", "ball", "apple", "art", "ah" };
	string str = "htarfbp";
	auto ret = alphabetical(words, str);
	for (auto wrd : ret)
		cout << wrd << " ";
	cout << endl;
	return 0;
}
