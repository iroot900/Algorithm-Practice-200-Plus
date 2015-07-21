#include <iostream>
#include <vector>
#include <random>
#include <stack>
#include <queue>
#include <time.h>
using namespace std;

template <typename T>
class Quack
{
	public:
		void pop()
		{
			if(!peeked.empty()) {peeked.pop(); return ;}
			if(!data.empty())
			{
				if(rand()&1)
				{
					 data.pop_front();
				}
				else
				{
					data.pop_back();
				}
			}	
		}

		T peek()
		{
			if(peeked.empty()&&!data.empty())
			{
				T obj;
				if(rand()&1)
				{
					obj=data.front(); data.pop_front();
				}
				else
				{
					obj=data.back(); data.pop_back();
				}
				peeked.push(obj);
				return obj;
			}
			else if(!peeked.empty()) return peeked.top();
		}

		bool empty()
		{
			return data.empty()&&peeked.empty();
		}

		void push(T obj)
		{
			data.push_back(obj);
		}
	private:
		deque<T> data;
		stack<T> peeked;
};

int main()
{
	srand(time(0));
	Quack<string> text;
	text.push("This");
	text.push("is");
	text.push("a");
	text.push("funny");
	text.push("game");
	text.push("for");
	text.push("all");
	text.push("of");
	text.push("us");

	while(!text.empty()) {cout<<text.peek()<<" "; text.pop();}
	cout<<endl;

	Quack<int> data;
	for(int i=0;i<9;++i) data.push(i);
	stack<int> sta;
	queue<int> que;
	while(!data.empty())
	{
		int num=data.peek(); data.pop();
		if(!data.empty()&&num>data.peek()) sta.push(num);
		else que.push(num);
	}	
	while(!que.empty()) {cout<<que.front()<<" ";que.pop();}
	while(!sta.empty()) {cout<<sta.top()<<" ";sta.pop();}
	cout<<endl;
}
