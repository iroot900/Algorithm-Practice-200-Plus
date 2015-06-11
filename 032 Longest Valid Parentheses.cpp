class Solution {
public:
    int longestValidParentheses(string s) {
        int len=0;
        stack<int > pos;
        for(int i=0;i<s.size();i++)
        {
            if(pos.empty()||!match(s[pos.top()],s[i]))
            {
                pos.push(i);
            }
            else
            {
                pos.pop();
                int start=0;
                if(pos.empty()) start=-1;
                else start=pos.top();
                len=max(len,i-start);
            }
        }
        return len;
    }
    bool match(char left,char right)
    {
        return left=='('&&right==')';
    }
};
