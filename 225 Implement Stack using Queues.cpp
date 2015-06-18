class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if((queA.empty()&&queB.empty())||queB.empty())
        {
            queA.push(x);
        }
        else
        {
            queB.push(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(queA.empty())
        {
            while(queB.size()!=1)
            {
                queA.push(queB.front()); queB.pop();
            }
            queB.pop();
        }
        else
        {
            while(queA.size()!=1)
            {
                queB.push(queA.front()); queA.pop();
            }
            queA.pop();
        }
    }

    // Get the top element.
    int top() {
        int data;
        if(queA.empty())
        {
            while(queB.size()!=1)
            {
                queA.push(queB.front()); queB.pop();
            }
             data=queB.front();
             queA.push(queB.front());
             queB.pop();
             return data;
        }
        else
        {
            while(queA.size()!=1)
            {
                queB.push(queA.front()); queA.pop();
            }
            data=queA.front();
            queB.push(queA.front());
            queA.pop();
            return data;
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return queA.empty()&&queB.empty();
    }
    
    private:
    queue<int> queA;
    queue<int> queB;
};
