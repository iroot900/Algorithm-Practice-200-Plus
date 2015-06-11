class Solution {
public:
    string countAndSay(int n) {
        string last(1,'1');
        string current;
        while(--n)
        {
            int i=1;int count=1;
            //again don't hack it, even look simple
            // find the main logic first, most important-- main logic .. 
            // use special little case find boundary condition.
            for(;i<last.size();i++)
            {   
                if(last[i]==last[i-1])
                {
                    ++count;continue;
                }
                else
                {
                    current+=(count+'0');
                    current+=last[i-1];
                    count=1;continue;
                }
            }
            current+=(count+'0');
            current+=last[i-1];
            last=current;
            current.clear();
        }
        return last;
    }
};
