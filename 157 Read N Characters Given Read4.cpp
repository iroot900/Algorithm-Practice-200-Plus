// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
     
     // info 
     // main logic
     // boundary
     
    int read(char *buf, int n) {
        int count=0;
        int i=0;
        for(;i+4<=n;i=i+4)
        {
            int ret=read4(buf+i);
            if(ret<4)
            {
                return count+ret;
            }
            count+=4;
        }
        
        char buff[4];
        int ret=read4(buff);
        int remain=min(ret,n-i);
        
            for(int j=0;j<remain;++j)
            {
                buf[i+j]=buff[j];
            }
            return i+remain;
    }
};
