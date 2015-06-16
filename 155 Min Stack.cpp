class MinStack {
public:
	int top()
	{
		if(!sta.empty())
		return sta.top();
	    throw -1;
	}
	
	void pop()
	{
		if(!sta.empty())
		{
			if(sta.top()==minV.top()) {minV.pop();} sta.pop();
		}
		else throw -1;
	}

	void push(int x)
	{
		sta.push(x);
		if(minV.empty()||x<=minV.top())
		{
			minV.push(x);
		}
	}

	int getMin()
	{
		if(!minV.empty())
		return minV.top();
		throw -1;
	}	

	private:
	stack<int> sta;
	stack<int> minV;
};
