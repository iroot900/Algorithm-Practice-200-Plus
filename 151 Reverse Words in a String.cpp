class Solution {
public:
    void reverseWords(string &s) {
        string ret;
        int n=s.size();
        if(n==0) return ;
        int len=0;
        int i=n-1;
        while(i>=0&&s[i]==' ') --i;// main logic. first there might be space start, take care of it. 
        for(;i>=0;)
        {
            if(s[i]!=' ')
            { 
                ++len;--i;
            }
            else
            {
                ret+=s.substr(i+1,len); // when space happens after word add. 
                ret+=" ";// need space 
                len=0;--i;
                while(i>=0&&s[i]==' ') --i;// there might be large space. take care of it. 
            }
        }
        if(s[0]!=' ')// if last not space, need add staff to it. 
        ret+=s.substr(0,len);
        else if (ret.size()>0)  // if space , check if add, need to pop out space 
        ret.pop_back();
        s=ret;
    }
};
