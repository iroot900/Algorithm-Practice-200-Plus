class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0) return vector<int>(1,0);
        if(n==1)
        {
            vector<int> ret(2,0);
            ret[0]=0;ret[1]=1;
            return ret;
        }
        auto last=grayCode(n-1);
        int len=last.size();
        vector<int> result(2*len); 
        for(int i=0;i<len;++i)
        {
            result[i]=last[i];
        }
        for(int i=len;i<2*len;++i)
        {
            result[i]=last[2*len-1-i]+(1<<(n-1));
        }
        return result;
    }
};
