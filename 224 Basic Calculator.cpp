class Solution {
public:
    int calculate(string s) {
        //two stack, one for number and one for symbol
        // (1+(4+5+2)-3)+(6+8)
        
        // a stack for data which provide data service to operator.
        // a stack for symbol, basiclly the most recent one's is the higher order one.
        // '(' it's in
        // '+-*-' compare with last, less or equal do all the previous opeartor. pop out and 
        // last. pop out all, 
        
        stack<int> data;
        stack<char> symbol;
        int n=s.size();
        for(int i=0;i<n;)
        {
            if(s[i]==' ') ++i;
            else if(isdigit(s[i]))
            {
                int start=i;
                while(i+1<n&&isdigit(s[i+1])) {++i;} 
                data.push(stoi(s.substr(start,i-start+1)));
                ++i;
            }
            else if(s[i]=='(')
            {
                symbol.push('(');++i;
            }
            else if(s[i]=='+'||s[i]=='-')
            {
                if(symbol.empty()||symbol.top()=='(') {symbol.push(s[i]);++i;}
                else 
                {
                    char sign=symbol.top(); symbol.pop();
                    int right=data.top(); data.pop();
                    int left=data.top(); data.pop();
                    if(sign=='-')
                    data.push(left-right);
                    else if(sign=='+')
                    data.push(left+right);
                }
            }
            else if(s[i]==')')
            {
                while(symbol.top()!='(')
                {
                    char sign=symbol.top(); symbol.pop();
                    int right=data.top(); data.pop();
                    int left=data.top(); data.pop();
                    if(sign=='-')
                    data.push(left-right);
                    else if(sign=='+')
                    data.push(left+right);
                }
                symbol.pop();
                ++i;
            }
        }
                while(!symbol.empty())
                {
                    char sign=symbol.top(); symbol.pop();
                    int right=data.top(); data.pop();
                    int left=data.top(); data.pop();
                    if(sign=='-')
                    data.push(left-right);
                    else if(sign=='+')
                    data.push(left+right);
                }
        return data.top();
    }
};
