class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n=s.size();
        if(n>12) return result;
        DFS( 0,0 , s, result, "");
        return result;
    }
    
    void DFS(int depth ,int index,string s, vector<string> &result, string solution)
    {
        if(depth==4&&index==s.size())
        {
            solution.pop_back();
            result.push_back(solution); return;
        }
        for(int i=1;i<4;++i )
        {
            if(index+i<=s.size())
            {
                string digit=s.substr(index,i);
                if(digit[0]=='0'&&digit.size()>1) continue;
                if(stoi(digit)<256)
                DFS( depth+1,index+i, s, result, solution+digit+'.');
            }
        }
    }
};
