class Solution {
public:
    string simplifyPath(string path) {
        // using a stack to handle this.. 
        stack<string> sta;
        int n=path.size();
        
        // Main logic of path.
        // get all symbol betwwen / /
        // if . go, .. go up. others, it's a direct
        
        for(int i=0;i<n;++i)
        {
            if(path[i]=='/') continue;
            else 
            {
                int start=i;
                while(i<n&&path[i]!='/')
                {
                    ++i;
                }
                string symbol=path.substr(start,i-start);
                if(symbol==".") continue;
                else if(symbol=="..") 
                {
                    if(!sta.empty())  sta.pop();
                }
                else
                {
                    sta.push(symbol);
                }
            }
        }
        string direct;
        while(!sta.empty())
        {
            direct="/"+sta.top()+direct;
            sta.pop();
        }

        if(direct.size()==0) direct.push_back('/');
        return direct;
    }
};
