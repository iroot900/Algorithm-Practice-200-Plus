// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    Solution () {buffer[0]='\0';}
    
    int read(char *buf, int n) {
        int num=0;
        
        int i=0;
        //
        // a b c 
        // du 1 2 3 4 
        
        // i=1  n=2;
        // i=2;  n==3;
        for(;i<n;++i)
        {
            if(buffer[i]!='\0')
            {
                buf[i]=buffer[i];
                ++num;
            }
            else break;
        }
        
        if(i==n)  //read them all needed. probabaly still reamins. 
        {
            int j=0;
            for(;;++j)
            {
                if(buffer[j+i]=='\0') break;
                buffer[j]=buffer[j+i];
            }
            buffer[j]='\0';
            return n;
            // there are still remaining.  should return now. or, if you keep reading, there will be overlow for buffer. 
        }
        else
        buffer[0]='\0';
        
        //if still remain.
        
        for(;i+4<=n;i+=4)
        {
            int ret=read4(buf+i);
            if(ret<4) 
            {
                return num+ret;
            }
            num+=4;
        }
        
        char buff[4];
        int ret=read4(buff);
        int remain=min(ret,n-i);
        for(int i=0;i<remain;++i)
        {
            buf[num+i]=buff[i];
        }
        
        int j=0;
        for(;j<ret-remain;++j)
        {
            buffer[j]=buff[j+remain];
        }
        buffer[j]='\0';
        return remain+num;
    }
    
    private:
    char buffer[5];
    
};
