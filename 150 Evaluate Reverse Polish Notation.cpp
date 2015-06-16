class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        int n=tokens.size();
        for(int i=0;i<n;++i)
        {
            if(tokens[i].size()==1&&(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"))
            {
                int right=sta.top(); sta.pop();
                int left=sta.top();sta.pop();
                int temp;
                switch(tokens[i][0])
                {
                    case '+':
                    temp=left+right;
                    break;
                    case '-':
                    temp=left-right;
                    break;
                    case '*':
                    temp=left*right;
                    break;
                    case '/':
                    temp=left/right;
                    break;
                }
                sta.push(temp);
            }
            else
            {
                sta.push(stoi(tokens[i]));
            }
        }
        return sta.top();
    }
};
