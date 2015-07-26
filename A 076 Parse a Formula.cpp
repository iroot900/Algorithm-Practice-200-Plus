//given a string such as "5+2x-(3y+2x-(7-2x)-9)=3+4y+x"
//x is know as a float. parse the string and output a float for y
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void cal(stack<char> &symbol ,stack<double> &data)
{
	double right=data.top(); data.pop();
	double left=data.top(); data.pop();
	if(symbol.top()=='+')	data.push(left+right);
	if(symbol.top()=='-')   data.push(left-right);
}

pair<double,double> parsing(string& str,double x)
{
	stack<double> data;
	stack<char> symbol;
	stack<double> ydata;
	
	for(int i=0;i<str.size();)
	{
		if(str[i]=='(')	
		{
			symbol.push('(');++i;
		}
		else if(str[i]==')')
		{
			while(symbol.top()!='(')
			{
				cal(symbol,data);
				cal(symbol,ydata);
				symbol.pop();
			}
			symbol.pop(); ++i;
		}
		else if(str[i]=='+'||str[i]=='-')
		{
			if(symbol.empty()||symbol.top()=='(')
			{
				symbol.push(str[i]);++i;
			}
			else
			{
				cal(symbol,data);
				cal(symbol,ydata);
				symbol.pop();
			}
		}
		else 
		{
			int end=str.find_first_of("+-()",i);
			if(end==string::npos) end=str.size();
			string num=str.substr(i,end-i);
			i=end;
			if(num.back()=='x')
			{
				num.pop_back();
				if(num.size()==0) data.push(x);
				else data.push(stod(num)*x);
				ydata.push(0);
			}
			else if(num.back()=='y')
			{
				num.pop_back();
				if(num.size()==0) ydata.push(1);
				else ydata.push(stod(num));
				data.push(0);
			}
			else 
			{
				data.push(stod(num)); 
				ydata.push(0);
			}
		}
	}

	while(!symbol.empty())
	{
		cal(symbol,data);
		cal(symbol,ydata);
		symbol.pop();
	}
	return {data.top(),ydata.top()};
}

double parsingExp(string& str, double x)
{
	int p=str.find_first_of("=");
	string leftStr=str.substr(0,p);
	string rightStr=str.substr(p+1);
	auto leftPair=parsing(leftStr,  x);
	auto rightPair=parsing(rightStr,  x);

	return (leftPair.first-rightPair.first)/(rightPair.second-leftPair.second);
}

int main()
{
    string str="5+2x-(3y+2x-(7-2x)-9)=3+4y+x";
	cout<<parsingExp(str,2)<<endl;
}
