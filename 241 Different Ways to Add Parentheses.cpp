class Solution {
public:

int cal(int left, int right, char oper)
{
	switch (oper)
	{
	case '+': return left + right;
	case '-': return left - right;
	case '*': return left * right;
	}
}

void DFS(string str, stack<int> data, stack<char> symbol, vector<int> &result)
{
	if (str.size() == 0)
	{
		while (!symbol.empty())  
		{
			int right = data.top(); data.pop(); int left = data.top(); data.pop();
			data.push(cal(left, right, symbol.top())); symbol.pop();
		}
		result.push_back(data.top()); return;
	}
	
	if (str[0] == '+' || str[0] == '-' || str[0] == '*')
	{
		auto temp = symbol; temp.push(str[0]);
		DFS(str.substr(1), data, temp, result);
		while (symbol.size() > 0)
		{
			int right = data.top(); data.pop(); int left = data.top(); data.pop();
			data.push(cal(left, right, symbol.top())); symbol.pop();
			auto temp = symbol; temp.push(str[0]);
			DFS(str.substr(1),data,temp,result);
		}
	}
	else
	{
		int p = str.find_first_of("+-*");
		if (p == string::npos) p = str.size();
		int num = stoi(str.substr(0, p));
		data.push(num);
		DFS(str.substr(p), data, symbol, result);
	}
}

vector<int> diffWaysToCompute(string input) {
    stack<int> data;
	stack<char> symbol;
	vector<int> result;
	DFS(input, data, symbol, result);
	return result;
  }
};
