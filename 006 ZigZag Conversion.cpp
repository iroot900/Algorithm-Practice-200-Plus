class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1||n<=numRows) return s;
        //first row would be. 
        // base=numRows+numRows-2
        // 0 0+base +base +base  (<s.size())
        // 1 1+(base-2) +base    
        // 2 2+(base-4) +base    <s.size();
        // 3 3+(base-6) +base
        // 4 4+ base
        string result;
        int base=numRows+numRows-2;
        for(int i=0;i<numRows;++i)
        {
            if(i!=0&&i!=numRows-1)
            {
                int bas=base-(2*i);
                int index=i;
                result+=s[index];
                while(1)
                {
                    if(index+bas<n)
                    {
                        result+=s[index+bas];
                    } else break;
                    if(index+base<n)
                    {
                        result+=s[index+base];
                        index+=base;
                    } else break;
                }
            }
            else
            {
                int index=i;
                result+=s[index];
                while(index+base<n)
                {
                    result+=s[index+base];
                    index+=base;
                } 
            }
        }
        return result;
    }
};
