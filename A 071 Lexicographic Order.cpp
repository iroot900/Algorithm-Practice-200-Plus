//Get Lexicographical Order From Dictionary
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

vector<char> lexiOrder(vector<string> words)
{
	vector<char> result;
	unordered_map<char, unordered_set<char>> graph;
	//incoming set. 
	unordered_map<char, int> incomings;
	int n = words.size();

	for (int i = 0; i < n - 1; ++i)
	{
		int len = min(words[i].size(), words[i + 1].size());
		for (int j = 0; j < len; ++j)
		{
			if (words[i][j] != words[i + 1][j]){
				graph[words[i][j]].insert(words[i + 1][j]);
				incomings[words[i + 1][j]]++; 
				break;
			}
		}
	}

	queue<char> que;
	for (char cha = 'a'; cha <= 'z'; ++cha)
	{ 
		if (incomings[cha] == 0) que.push(cha);
	}

	while (!que.empty())
	{ 
		auto node = que.front(); que.pop();
		result.push_back(node);
		for (auto nei : graph[node])
		{
			incomings[nei]--;
			if (incomings[nei] == 0) que.push(nei);
		}
	} 
	if (any_of(begin(incomings), end(incomings), [](pair<char, int> pir) {return pir.second != 0; })) { cout << "Not valid! " << endl; return{}; }
	return result;
}
int main()
{
	vector<string> words = { "ze", "yf", "xd", "wd", "vd", "ua", "tt", "sz", "rd",
		"qd", "pz", "op", "nw", "mt", "ln", "ko", "jm", "il",
		"ho", "gk", "fa", "ed", "dg", "ct", "bb","ba" };
	auto ret = lexiOrder(words);
	for (auto cha : ret)
		cout << cha << " ";
	cout << endl<<endl;


	vector<string> words2 = { "ez","ze", "yf", "xd", "wd", "vd", "ua", "tt", "sz", "rd",
		"qd", "pz", "op", "nw", "mt", "ln", "ko", "jm", "il",
		"ho", "gk", "fa", "ed", "dg", "ct", "bb", "ba" };
	auto ret2 = lexiOrder(words2);
	for (auto cha : ret2)
		cout << cha << " ";
	cout << endl;
	return 0;
}
