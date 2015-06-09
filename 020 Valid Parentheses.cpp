class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(sta.empty()) sta.push(s[i]);
            else
            {
                if(valid(sta.top(),s[i])) sta.pop();
                else sta.push(s[i]);
            }
        }
        return sta.size()==0;
    }
    
    bool valid(char a, char b)
    {
        switch(a)
        {
            case '(': return b==')';break;
            case '{': return b=='}';break;
            case '[': return b==']';break;
            default:
            return false;
        }
    }
};
