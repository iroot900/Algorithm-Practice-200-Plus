class Solution {
public:
    int calculate(string s) {
        //two stack
        // main logic. 
        // if number then, number's in
        // if symbol, compare with last symbol, last is more advance, then go last. 
        stack<long> data;
        stack<char> symbol;
        int start=0;
        int n=s.size();
        if(n==0) return 0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
            {
                long num=stol(s.substr(start,i-start));
                data.push(num);
                start=i+1;
                char sym=s[i];
                
                        while(!symbol.empty()&&!great(sym,symbol.top()))
                        {
                            char symb=symbol.top(); symbol.pop();
                            long right=data.top(); data.pop();
                            long left=data.top(); data.pop();
                            data.push(cal(left,right,symb));
                        }
                        symbol.push(sym);
            }
        }
        data.push(stol(s.substr(start)));
        
                        while(!symbol.empty())
                        {
                            char symb=symbol.top(); symbol.pop();
                            long right=data.top(); data.pop();
                            long left=data.top(); data.pop();
                            data.push(cal(left,right,symb));
                        }
                        
        return data.top();
    }
    
    bool great(char left, char right)
    {
        if((left=='*'||left=='/')&&(right=='+'||right=='-'))
        return true;
        else return false;
    }
    
    long cal(long left,long right,char symb)
    {
        switch(symb)
        {
            case '+': return left+right;
            case '-': return left-right;
            case '*': return left*right;
            case '/': return left/right;
        }
    }
};
