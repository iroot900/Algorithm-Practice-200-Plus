int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        
        int i=0;
        while(!que.empty())
        {
            if(i==n) return n;
            buf[i++]=que.front(); que.pop();
        } 
        
        int current=i;
        for(;current+4<=n;current+=4)
        {
            int cha=read4(buf+current);
            if(cha<4) return current+cha;
        }
         
        int remain=n-current;
        if(remain==0) return n;
        else 
        {
            char buff[4];
            int last=read4(buff);
            int need=min(last,remain);
            for(int i=0;i<last;++i) 
            {
                if(i<need)   buf[current+i]=buff[i];
                else    { que.push(buff[i]); }
            }
            return current+need;
        }
    }

private:
    queue<char> que;
};
