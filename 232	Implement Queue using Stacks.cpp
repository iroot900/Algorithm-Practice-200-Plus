class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		inStack.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (!outStack.empty()) outStack.pop();
		else if (!inStack.empty())
		{
			while (!inStack.empty())
			{
				outStack.push(inStack.top()); inStack.pop();
			}
			outStack.pop();
		}
	}

	// Get the front element.
	int peek(void) {

		if (!outStack.empty()) return outStack.top();
		else if (!inStack.empty())
		{
			while (!inStack.empty())
			{
				outStack.push(inStack.top()); inStack.pop();
			}
			return outStack.top();
		}
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return inStack.empty() && outStack.empty();
	}
private:
	// main logic    two stack to do queue. 
	stack<int> inStack;
	stack<int> outStack;
};
